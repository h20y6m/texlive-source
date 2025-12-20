/*
 * fontconfig/src/fcinit.c
 *
 * Copyright © 2001 Keith Packard
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of the author(s) not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission.  The authors make no
 * representations about the suitability of this software for any purpose.  It
 * is provided "as is" without express or implied warranty.
 *
 * THE AUTHOR(S) DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#include "fcint.h"
#include <stdlib.h>

#if defined(FC_ATOMIC_INT_NIL)
#pragma message("Could not find any system to define atomic_int macros, library may NOT be thread-safe.")
#endif
#if defined(FC_MUTEX_IMPL_NIL)
#pragma message("Could not find any system to define mutex macros, library may NOT be thread-safe.")
#endif
#if defined(FC_ATOMIC_INT_NIL) || defined(FC_MUTEX_IMPL_NIL)
#pragma message("To suppress these warnings, define FC_NO_MT.")
#endif

#ifdef _WIN32
extern char * kpse_var_value(char *a);
#endif

static FcConfig *
FcInitFallbackConfig (const FcChar8 *sysroot)
{
    FcConfig	*config;
#ifndef _WIN32
    const FcChar8 *fallback = (const FcChar8 *) ""	\
	"<fontconfig>" \
	FC_DEFAULT_FONTS \
	"  <dir prefix=\"xdg\">fonts</dir>" \
	"  <cachedir>" FC_CACHEDIR "</cachedir>" \
	"  <cachedir prefix=\"xdg\">fontconfig</cachedir>" \
	"  <include ignore_missing=\"yes\">" CONFIGDIR "</include>" \
	"  <include ignore_missing=\"yes\" prefix=\"xdg\">fontconfig/conf.d</include>" \
	"  <include ignore_missing=\"yes\" prefix=\"xdg\">fontconfig/fonts.conf</include>" \
	"</fontconfig>";
#endif /* !_WIN32 */

    config = FcConfigCreate ();
    if (!config)
	goto bail0;
    FcConfigSetSysRoot (config, sysroot);
#ifndef _WIN32
    if (!FcConfigParseAndLoadFromMemory (config, fallback, FcFalse))
	goto bail1;
#endif /* !_WIN32 */

    return config;

bail1:
    FcConfigDestroy (config);
bail0:
    return 0;
}

int
FcGetVersion (void)
{
    return FC_VERSION;
}

#ifdef WIN32
static int is_dir (char *buff)
{
    struct stat stats;

    return stat (buff, &stats) == 0 && S_ISDIR (stats.st_mode);
}
#endif

/*
 * Load the configuration files
 */
FcConfig *
FcInitLoadOwnConfig (FcConfig *config)
{
#ifdef WIN32
    FcChar8 *kp8 = NULL;
    char *p;

    p = kpse_var_value("XE_FC_CACHEDIR");
    if(p == NULL)
      p = kpse_var_value("FC_CACHEDIR");
    if(p == NULL) {
      fprintf(stderr, "I cannot determine FC_CACHEDIR. ");
      fprintf(stderr, "Define FC_CACHEDIR in texmf.cnf.\n");
      exit(1);
    } else {
      kp8 = (FcChar8 *)malloc(strlen(p) + 1);
      strcpy(kp8, p);
      free(p);
    }
#endif

    if (!config)
    {
	config = FcConfigCreate ();
	if (!config)
	    return NULL;
    }

    FcInitDebug ();

    if (!FcConfigParseAndLoad (config, 0, FcTrue))
    {
	const FcChar8 *sysroot = FcConfigGetSysRoot (config);
	FcConfig *fallback = FcInitFallbackConfig (sysroot);

#ifdef WIN32
        if (fallback) {
    		(void)FcConfigAddCacheDir (fallback, (FcChar8 *) kp8);
		if(!kp8 || is_dir(kp8) == 0) {
			if(kp8)
				fprintf(stderr, "%s does not exist.\n", kp8);
			fprintf(stderr, "Kpathsea is not working.\n");
			exit(5);
		}
		free(kp8);
	}
    	return fallback;
#else
	FcConfigDestroy (config);

	return fallback;
#endif
    }
#ifdef _MSC_VER
#define FC_TEMPLATEDIR "."
#endif

    (void) FcConfigParseOnly (config, (const FcChar8 *)FC_TEMPLATEDIR, FcFalse);

    if (config->cacheDirs && config->cacheDirs->num == 0)
#ifdef WIN32
    {
	(void)FcConfigAddCacheDir (config, (FcChar8 *) kp8);
	free(kp8);
	if (config->cacheDirs && config->cacheDirs->num == 0) {
		fprintf (stderr,
			 "Fontconfig warning: no <cachedir> elements found. Check configuration.\n");
		return 0;
	}
    }
#else
    {
	FcChar8 *prefix, *p;
	size_t plen;
	FcBool have_own = FcFalse;
	char *env_file, *env_path;

	env_file = getenv ("FONTCONFIG_FILE");
	env_path = getenv ("FONTCONFIG_PATH");
	if ((env_file != NULL && env_file[0] != 0) ||
	    (env_path != NULL && env_path[0] != 0))
	    have_own = FcTrue;

	if (!have_own)
	{
	    fprintf (stderr,
		     "Fontconfig warning: no <cachedir> elements found. Check configuration.\n");
	    fprintf (stderr,
		     "Fontconfig warning: adding <cachedir>%s</cachedir>\n",
		     FC_CACHEDIR);
	}
	prefix = FcConfigXdgCacheHome ();
	if (!prefix)
	    goto bail;
	plen = strlen ((const char *)prefix);
	p = realloc (prefix, plen + 12);
	if (!p)
	    goto bail;
	prefix = p;
	memcpy (&prefix[plen], FC_DIR_SEPARATOR_S "fontconfig", 11);
	prefix[plen + 11] = 0;
	if (!have_own)
	    fprintf (stderr,
		     "Fontconfig warning: adding <cachedir prefix=\"xdg\">fontconfig</cachedir>\n");

	if (!FcConfigAddCacheDir (config, (FcChar8 *) FC_CACHEDIR) ||
	    !FcConfigAddCacheDir (config, (FcChar8 *) prefix))
	{
	    FcConfig *fallback;
	    const FcChar8 *sysroot;

	  bail:
	    sysroot = FcConfigGetSysRoot (config);
	    fprintf (stderr,
		     "Fontconfig error: out of memory");
	    if (prefix)
		FcStrFree (prefix);
	    fallback = FcInitFallbackConfig (sysroot);
	    FcConfigDestroy (config);

	    return fallback;
	}
	FcStrFree (prefix);
    }

#endif
    return config;
}

FcConfig *
FcInitLoadConfig (void)
{
    return FcInitLoadOwnConfig (NULL);
}

/*
 * Load the configuration files and scan for available fonts
 */
FcConfig *
FcInitLoadOwnConfigAndFonts (FcConfig *config)
{
    config = FcInitLoadOwnConfig (config);
    if (!config)
	return 0;
    if (!FcConfigBuildFonts (config))
    {
	FcConfigDestroy (config);
	return 0;
    }
    return config;
}

FcConfig *
FcInitLoadConfigAndFonts (void)
{
    return FcInitLoadOwnConfigAndFonts (NULL);
}

/*
 * Initialize the default library configuration
 */
FcBool
FcInit (void)
{
    return FcConfigInit ();
}

/*
 * Free all library-allocated data structures.
 */
void
FcFini (void)
{
    FcConfigFini ();
    FcConfigPathFini ();
    FcDefaultFini ();
    FcObjectFini ();
    FcCacheFini ();
}

/*
 * Reread the configuration and available font lists
 */
FcBool
FcInitReinitialize (void)
{
    FcConfig	*config;
    FcBool	ret;

    config = FcInitLoadConfigAndFonts ();
    if (!config)
	return FcFalse;
    ret = FcConfigSetCurrent (config);
    /* FcConfigSetCurrent() increases the refcount.
     * decrease it here to avoid the memory leak.
     */
    FcConfigDestroy (config);

    return ret;
}

FcBool
FcInitBringUptoDate (void)
{
    FcConfig	*config = FcConfigReference (NULL);
    FcBool	ret = FcTrue;
    time_t	now;

    if (!config)
	return FcFalse;
    /*
     * rescanInterval == 0 disables automatic up to date
     */
    if (config->rescanInterval == 0)
	goto bail;
    /*
     * Check no more often than rescanInterval seconds
     */
    now = time (0);
    if (config->rescanTime + config->rescanInterval - now > 0)
	goto bail;
    /*
     * If up to date, don't reload configuration
     */
    if (FcConfigUptoDate (0))
	goto bail;
    ret = FcInitReinitialize ();
bail:
    FcConfigDestroy (config);

    return ret;
}

#define __fcinit__
#include "fcaliastail.h"
#undef __fcinit__
