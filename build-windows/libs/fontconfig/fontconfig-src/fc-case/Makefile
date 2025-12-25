SHELL = sh
MAKE = make
PROGRAM = fc-case.exe
SRCS = fc-case.c
OBJS = fc-case.obj
CC = cl

CFLAGS = -nologo -O2 -MD -DWIN32=1 -DHAVE_CONFIG_H \
-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE \
-D_CRT_OBSOLETE_NO_DEPRECATE -DNO_KPSE_DLL=1
DBG =

#CFLAGS = -nologo -Od -Zi -MD -DWIN32=1 -DHAVE_CONFIG_H \
#-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE \
#-D_CRT_OBSOLETE_NO_DEPRECATE
#DBG = -link -DEBUG:FULL

INCFLAGS = -I. -I.. -I../src -I../../../texk/kpathsea \
-I../../freetype/include

LLIBS = ../../freetype/objs/freetype.lib \
../../expat/lib/libexpat.lib ../../../texk/kpathsea/libkpathsea.lib

SYSLIBS = user32.lib advapi32.lib shell32.lib

all: $(PROGRAM)

$(PROGRAM): $(LLIBS) $(OBJS)
	$(CC) -Fe$@ $(OBJS) $(LLIBS) $(DBG) $(SYSLIBS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $(SRCS)
