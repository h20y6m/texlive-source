#ifndef KANJI_H
#define KANJI_H
#include "ptexenc/ptexenc.h"
#include <ptexenc/unicode.h>

#define getintone(w) ((w).cint1)
#define setintone(w,a) ((w).cint1=(a))

#define delcharfield(x) ((unsigned)(x) & 0x1FFFFF)
#define delfamfield(x)  ((unsigned)(x)>>21)
#endif

