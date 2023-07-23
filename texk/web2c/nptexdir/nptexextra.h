#include <nptexdir/etex_version.h> /* for ETEX_VERSION */
#include <nptexdir/xetex_version.h> /* for XETEX_VERSION */
#include <nptexdir/nptex_version.h> /* for NPTEX_VERSION */

#define BANNER "This is npTeX, Version 3.141592653-" ETEX_VERSION "-" XETEX_VERSION "-" NPTEX_VERSION
#define COPYRIGHT_HOLDER "SIL International, Jonathan Kew and Khaled Hosny"
#define AUTHOR "Japanese TeX Development Community"
#define PROGRAM_HELP NPTEXHELP
#define BUG_ADDRESS "issue@texjp.org"
#define DUMP_VAR TEXformatdefault
#define DUMP_LENGTH_VAR formatdefaultlength
#define DUMP_OPTION "fmt"
#define DUMP_EXT ".fmt"
#define INPUT_FORMAT kpse_tex_format
#define INI_PROGRAM "npinitex"
#define VIR_PROGRAM "npvirtex"
