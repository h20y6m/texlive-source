
#  include "nptexd.h"
/* this will define npTeX, which we can use in later conditionals */

#  include <xetexdir/xetexextra.h>

/* We observe nopdfoutput in order to determine whether output mode is
 * pdf or xdv. */
#  define SYNCTEX_OFFSET_IS_PDF (nopdfoutput==0)
#  define SYNCTEX_OUTPUT (nopdfoutput!=0?"xdv":"pdf")

#define SYNCTEX_CURH ((nopdfoutput==0)?(curh+4736287):curh)
#define SYNCTEX_CURV ((nopdfoutput==0)?(curv+4736287):curv)

/*  WARNING:
    The definition below must be in sync with their eponym declarations in synctex-xetex.ch1
*/
#  define synchronization_field_size 1

/* in XeTeX, "halfword" fields are at least 32 bits, so we'll use those for
 * tag and line so that the sync field size is only one memory_word. */
#  define SYNCTEX_TAG_MODEL(NODE,TYPE)\
                mem[NODE+TYPE##_node_size-synchronization_field_size].hh.lhfield
#  define SYNCTEX_LINE_MODEL(NODE,TYPE)\
                mem[NODE+TYPE##_node_size-synchronization_field_size].hh.rh
