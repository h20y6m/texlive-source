/*
 * fontconfig/fc-cache/fc-cache.c
 *
 * Copyright © 2002 Keith Packard
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

#ifdef _WIN32
#define X_OK 0
#define F_OK 0
#include <kpathsea/c-proto.h>
#include <kpathsea/variable.h>
#endif

#ifdef HAVE_CONFIG_H
#include <config.h>
#else
#ifdef linux
#define HAVE_GETOPT_LONG 1
#endif
#define HAVE_GETOPT 1
#endif

#include <fontconfig/fontconfig.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef _WIN32
#include <unistd.h>
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <locale.h>

#if defined (_WIN32)
#ifndef STRICT
#define STRICT
#endif
#include <windows.h>
#define sleep(x) Sleep((x) * 1000)
#undef STRICT
#endif

#ifdef ENABLE_NLS
#include <libintl.h>
#define _(x)		(dgettext(GETTEXT_PACKAGE, x))
#else
#define dgettext(d, s)	(s)
#define _(x)		(x)
#endif

#ifndef O_BINARY
#define O_BINARY 0
#endif

#ifndef S_ISDIR
#define S_ISDIR(m) (((m) & _S_IFMT) == _S_IFDIR)
#endif

#ifndef HAVE_GETOPT
#define HAVE_GETOPT 0
#endif
#ifndef HAVE_GETOPT_LONG
#define HAVE_GETOPT_LONG 0
#endif

#if HAVE_GETOPT_LONG
#undef  _GNU_SOURCE
#define _GNU_SOURCE
#include <getopt.h>
const struct option longopts[] = {
    {"error-on-no-fonts", 0, 0, 'E'},
    {"force", 0, 0, 'f'},
    {"really-force", 0, 0, 'r'},
    {"sysroot", required_argument, 0, 'y'},
    {"system-only", 0, 0, 's'},
    {"version", 0, 0, 'V'},
    {"verbose", 0, 0, 'v'},
    {"help", 0, 0, 'h'},
    {NULL,0,0,0},
};
#else
#if HAVE_GETOPT
extern char *optarg;
#ifndef _WIN32
extern int optind, opterr, optopt;
#endif
#endif
#endif

static void
usage (char *program, int error)
{
    FILE *file = error ? stderr : stdout;
#if HAVE_GETOPT_LONG
#if defined(_WIN32)
    fprintf (file, _("usage: %s [-EfrsvVh] [--error-on-no-fonts] [--force|--really-force] [--system-only] [--verbose] [--version] [--help] [dirs]\n"),
	     program);
#else
    fprintf (file, _("usage: %s [-EfrsvVh] [-y SYSROOT] [--error-on-no-fonts] [--force|--really-force] [--sysroot=SYSROOT] [--system-only] [--verbose] [--version] [--help] [dirs]\n"),
	     program);
#endif /* _WIN32 */
#else
#if defined(_WIN32)
    fprintf (file, _("usage: %s [-EfrsvVh] [dirs]\n"),
	     program);
#else
    fprintf (file, _("usage: %s [-EfrsvVh] [-y SYSROOT] [dirs]\n"),
	     program);
#endif /* _WIN32 */
#endif
    fprintf (file, _("Build font information caches in [dirs]\n"
		     "(all directories in font configuration by default).\n"));
    fprintf (file, "\n");
#if HAVE_GETOPT_LONG
    fprintf (file, _("  -E, --error-on-no-fonts  raise an error if no fonts in a directory\n"));
    fprintf (file, _("  -f, --force              scan directories with apparently valid caches\n"));
    fprintf (file, _("  -r, --really-force       erase all existing caches, then rescan\n"));
    fprintf (file, _("  -s, --system-only        scan system-wide directories only\n"));
#if !defined(_WIN32)
    fprintf (file, _("  -y, --sysroot=SYSROOT    prepend SYSROOT to all paths for scanning\n"));
#endif /* !_WIN32 */
    fprintf (file, _("  -v, --verbose            display status information while busy\n"));
    fprintf (file, _("  -V, --version            display font config version and exit\n"));
    fprintf (file, _("  -h, --help               display this help and exit\n"));
#else
    fprintf (file, _("  -E         (error-on-no-fonts)\n"));
    fprintf (file, _("                       raise an error if no fonts in a directory\n"));
    fprintf (file, _("  -f         (force)   scan directories with apparently valid caches\n"));
    fprintf (file, _("  -r,   (really force) erase all existing caches, then rescan\n"));
    fprintf (file, _("  -s         (system)  scan system-wide directories only\n"));
#if !defined(_WIN32)
    fprintf (file, _("  -y SYSROOT (sysroot) prepend SYSROOT to all paths for scanning\n"));
#endif /* !_WIN32 */
    fprintf (file, _("  -v         (verbose) display status information while busy\n"));
    fprintf (file, _("  -V         (version) display font config version and exit\n"));
    fprintf (file, _("  -h         (help)    display this help and exit\n"));
#endif
    exit (error);
}

static FcStrSet *processed_dirs;

static int
scanDirs (FcStrList *list, FcConfig *config, FcBool force, FcBool really_force, FcBool verbose, FcBool error_on_no_fonts, int *changed)
{
    int		    ret = 0;
    const FcChar8   *dir;
    FcStrSet	    *subdirs;
    FcStrList	    *sublist;
    FcCache	    *cache;
    struct stat	    statb;
    FcBool	    was_valid, was_processed = FcFalse;
    int		    i;
    const FcChar8   *sysroot = FcConfigGetSysRoot (config);

    /*
     * Now scan all of the directories into separate databases
     * and write out the results
     */
    while ((dir = FcStrListNext (list)))
    {
#ifdef _WIN32 /* we don't show looped-dir messages */
	if (FcStrSetMember (processed_dirs, dir))
	{
	    continue;
	}
#endif /* _WIN32 */
	if (verbose)
	{
	    if (sysroot)
		printf ("[%s]", sysroot);
	    printf ("%s: ", dir);
	    fflush (stdout);
	}

#ifndef _WIN32 /* we don't show looped-dir messages */
	if (FcStrSetMember (processed_dirs, dir))
	{
	    if (verbose)
		printf (_("skipping, looped directory detected\n"));
	    continue;
	}
#endif /* !_WIN32 */

    FcChar8 *rooted_dir = NULL;
    if (sysroot)
    {
        rooted_dir = FcStrPlus(sysroot, dir);
    }
    else {
        rooted_dir = FcStrCopy(dir);
    }

	if (stat ((char *) rooted_dir, &statb) == -1)
	{
	    switch (errno) {
	    case ENOENT:
	    case ENOTDIR:
		if (verbose)
		    printf (_("skipping, no such directory\n"));
		break;
	    default:
		fprintf (stderr, "\"%s\": ", dir);
		perror ("");
		ret++;
		break;
	    }
	    FcStrFree (rooted_dir);
	    rooted_dir = NULL;
	    continue;
	}

    FcStrFree(rooted_dir);
    rooted_dir = NULL;

	if (!S_ISDIR (statb.st_mode))
	{
	    fprintf (stderr, _("\"%s\": not a directory, skipping\n"), dir);
	    continue;
	}
	was_processed = FcTrue;

/* 
   In the case of _WIN32, we remove all caches if really_force
   is FcTrue at the very first. Thus the following is not
   necessary.
*/
#if !defined(_WIN32)
	if (really_force)
	{
	    FcDirCacheUnlink (dir, config);
	}
#endif

	cache = NULL;
	was_valid = FcFalse;
	if (!force) {
	    cache = FcDirCacheLoad (dir, config, NULL);
	    if (cache)
		was_valid = FcTrue;
	}
	
	if (!cache)
	{
	    (*changed)++;
	    cache = FcDirCacheRead (dir, FcTrue, config);
	    if (!cache)
	    {
		fprintf (stderr, _("\"%s\": scanning error\n"), dir);
		ret++;
		continue;
	    }
	}

	if (was_valid)
	{
	    if (verbose)
		printf (_("skipping, existing cache is valid: %d fonts, %d dirs\n"),
			FcCacheNumFont (cache), FcCacheNumSubdir (cache));
	}
	else
	{
	    if (verbose)
		printf (_("caching, new cache contents: %d fonts, %d dirs\n"),
			FcCacheNumFont (cache), FcCacheNumSubdir (cache));

/* #ifndef _WIN32 */
	    if (!FcDirCacheValid (dir))
	    {
		fprintf (stderr, _("%s: failed to write cache\n"), dir);
		(void) FcDirCacheUnlink (dir, config);
		ret++;
	    }
/* #endif */ /* !_WIN32 */
	}

	subdirs = FcStrSetCreate ();
	if (!subdirs)
	{
	    fprintf (stderr, _("%s: Can't create subdir set\n"), dir);
	    ret++;
	    FcDirCacheUnload (cache);
	    continue;
	}
	for (i = 0; i < FcCacheNumSubdir (cache); i++)
	    FcStrSetAdd (subdirs, FcCacheSubdir (cache, i));
	
	FcDirCacheUnload (cache);

	sublist = FcStrListCreate (subdirs);
	FcStrSetDestroy (subdirs);
	if (!sublist)
	{
	    fprintf (stderr, _("%s: Can't create subdir list\n"), dir);
	    ret++;
	    continue;
	}
	FcStrSetAdd (processed_dirs, dir);
	ret += scanDirs (sublist, config, force, really_force, verbose, error_on_no_fonts, changed);
	FcStrListDone (sublist);
    }

    if (error_on_no_fonts && !was_processed)
	ret++;
    return ret;
}

static FcBool
cleanCacheDirectories (FcConfig *config, FcBool verbose)
{
    FcStrList	*cache_dirs = FcConfigGetCacheDirs (config);
    FcChar8	*cache_dir;
    FcBool	ret = FcTrue;

    if (!cache_dirs)
	return FcFalse;
    while ((cache_dir = FcStrListNext (cache_dirs)))
    {
	if (!FcDirCacheClean (cache_dir, verbose))
	{
	    ret = FcFalse;
	    break;
	}
    }
    FcStrListDone (cache_dirs);
    return ret;
}

int
main (int argc, char **argv)
{
    FcStrSet	*dirs;
    FcStrList	*list;
    FcBool    	verbose = FcFalse;
    FcBool	force = FcFalse;
    FcBool	really_force = FcFalse;
    FcBool	systemOnly = FcFalse;
    FcBool	error_on_no_fonts = FcFalse;
    FcConfig	*config;
    FcChar8     *sysroot = NULL;
    int		i;
    int		changed;
    int		ret;
#if HAVE_GETOPT_LONG || HAVE_GETOPT
    int		c;

    setlocale (LC_ALL, "");

#ifdef _WIN32
    kpse_set_program_name(argv[0], NULL);
#endif

#if HAVE_GETOPT_LONG
    while ((c = getopt_long (argc, argv, "Efrsy:Vvh", longopts, NULL)) != -1)
#else
    while ((c = getopt (argc, argv, "Efrsy:Vvh")) != -1)
#endif
    {
	switch (c) {
	case 'E':
	    error_on_no_fonts = FcTrue;
	    break;
	case 'r':
#if !defined(_WIN32)
	    really_force = FcTrue;
#endif /* _WIN32 */
	    /* fall through */
	case 'f':
#if defined(_WIN32)
/* 
   In the case of Windows, -r and -f are the same, because
   all cache files are removed in a special way.
*/
	    really_force = FcTrue;
#endif /* _WIN32 */
	    force = FcTrue;
	    break;
	case 's':
	    systemOnly = FcTrue;
	    break;
	case 'y':
#if !defined(_WIN32)
	    sysroot = FcStrCopy ((const FcChar8 *)optarg);
#endif /* !_WIN32 */
	    break;
	case 'V':
	    fprintf (stderr, "fontconfig version %d.%d.%d\n",
		     FC_MAJOR, FC_MINOR, FC_REVISION);
	    exit (0);
	case 'v':
	    verbose = FcTrue;
	    break;
	case 'h':
	    usage (argv[0], 0);
	default:
	    usage (argv[0], 1);
	}
    }
    i = optind;
#else
    i = 1;
#endif

#ifdef _WIN32
/* Always print (2014 ak) */
    printf ("Note that it needs some time to create caches,\n"
	    "especially if there are many large font files.\n"
	    "Wait with patience.\n\n");
#endif

#if defined(_WIN32)
/*
   In the case of -r and -f options (they are equivalent on Windows)
   remove all cache files here in our special way.
   In the default case, unlink() fails in most cases, so "foo.NEW"
   cannot be renamed as "foo".
*/
   if (really_force) {
       char *fname;
       char *cdir;
       DIR *dp;
       struct dirent *de;

       cdir = kpse_var_value ("XE_FC_CACHEDIR");
       if (cdir == NULL) {
          cdir = kpse_var_value ("FC_CACHEDIR");
       }

       if (cdir) {
          if ((dp = opendir(cdir))) {
             while((de = readdir(dp))) {
                if (strcmp(de->d_name, ".") &&
                    strcmp(de->d_name, "..") &&
                    stricmp(de->d_name, "readme.txt")) {
                   fname = malloc (strlen(cdir) + strlen(de->d_name) + 2);
                   strcpy (fname, cdir);
                   strcat (fname, "/");
                   strcat (fname, de->d_name);
                   (void) remove (fname);
                   free (fname);
                }
             }
             closedir (dp);
          }
          free (cdir);
       }
    }
#endif /* _WIN32 */

    if (systemOnly)
	FcConfigEnableHome (FcFalse);
    if (sysroot)
    {
	FcConfigSetSysRoot (NULL, sysroot);
	FcStrFree (sysroot);
	config = FcConfigGetCurrent();
    }
    else
    {
	config = FcInitLoadConfig ();
    }
    if (!config)
    {
	fprintf (stderr, _("%s: Can't initialize font config library\n"), argv[0]);
	return 1;
    }
    FcConfigSetCurrent (config);

    if (argv[i])
    {
	dirs = FcStrSetCreate ();
	if (!dirs)
	{
	    fprintf (stderr, _("%s: Can't create list of directories\n"),
		     argv[0]);
	    return 1;
	}
	while (argv[i])
	{
	    if (!FcStrSetAddFilename (dirs, (FcChar8 *) argv[i]))
	    {
		fprintf (stderr, _("%s: Can't add directory\n"), argv[0]);
		return 1;
	    }
	    i++;
	}
	list = FcStrListCreate (dirs);
	FcStrSetDestroy (dirs);
    }
    else
	list = FcConfigGetFontDirs (config);

    if ((processed_dirs = FcStrSetCreate()) == NULL) {
	fprintf(stderr, _("Out of Memory\n"));
	return 1;
    }

    if (verbose)
    {
	const FcChar8 *dir;

	printf ("Font directories:\n");
	while ((dir = FcStrListNext (list)))
	{
	    printf ("\t%s\n", dir);
	}
	FcStrListFirst(list);
    }
    changed = 0;
    ret = scanDirs (list, config, force, really_force, verbose, error_on_no_fonts, &changed);
    FcStrListDone (list);

    /*
     * Try to create CACHEDIR.TAG anyway.
     * This expects the fontconfig cache directory already exists.
     * If it doesn't, it won't be simply created.
     */
    FcCacheCreateTagFile (config);

    FcStrSetDestroy (processed_dirs);

    cleanCacheDirectories (config, verbose);

    FcConfigDestroy (config);
    FcFini ();
    /* 
     * Now we need to sleep a second  (or two, to be extra sure), to make
     * sure that timestamps for changes after this run of fc-cache are later
     * then any timestamps we wrote.  We don't use gettimeofday() because
     * sleep(3) can't be interrupted by a signal here -- this isn't in the
     * library, and there aren't any signals flying around here.
     */
    /* the resolution of mtime on FAT is 2 seconds */
    if (changed)
	sleep (2);
    if (verbose)
	printf ("%s: %s\n", argv[0], ret ? _("failed") : _("succeeded"));
    return ret;
}
