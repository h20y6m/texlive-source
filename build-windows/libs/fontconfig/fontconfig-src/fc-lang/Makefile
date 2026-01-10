SHELL = sh
MAKE = make
PROGRAM = fc-lang.exe
SRCS = fc-lang.c
OBJS = fc-lang.obj
CC = cl
CFLAGS = -nologo -W0 -O2 -MT -DWIN32=1 -DHAVE_CONFIG_H \
-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE \
-D_CRT_OBSOLETE_NO_DEPRECATE -DNO_KPSE_DLL=1 -wd4819
DBG=
#
#CFLAGS = -nologo -W0 -Od -Zi -MT -DWIN32=1 -DHAVE_CONFIG_H \
#-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE \
#-D_CRT_OBSOLETE_NO_DEPRECATE
#DBG = -link -DEBUG:FULL
#

INCFLAGS = -I. -I.. -I../src -I../../../texk/kpathsea \
-I../../../texk -I../../freetype/include

LLIBS = ../../freetype/objs/freetype.lib \
../../expat/lib/libexpat.lib  ../../../texk/kpathsea/libkpathsea.lib \
user32.lib advapi32.lib shell32.lib

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) -Fe$@ $(OBJS) $(LLIBS) $(DBG) -link /manifest

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $(SRCS)
