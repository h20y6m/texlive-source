SHELL = sh
MAKE = make
PROGRAM = fc-cat.exe
SRCS = fc-cat.c
OBJS = fc-cat.obj
CC = cl
CFLAGS = -nologo -O2 -MT -DWIN32=1 -DHAVE_CONFIG_H \
-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE \
-D_CRT_OBSOLETE_NO_DEPRECATE -DNO_KPSE_DLL=1
DBG= -link /manifest

#
#CFLAGS = -nologo -Od -Zi -MT -DWIN32=1 -DHAVE_CONFIG_H \
#-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE \
#-D_CRT_OBSOLETE_NO_DEPRECATE
#DBG = -link -DEBUG
#

INCFLAGS = -I. -I.. -I../src -I../../../texk/kpathsea \
-I../../../texk -I../../freetype/include

LLIBS = ../src/libfontconfig.lib ../../freetype/objs/freetype.lib \
../../expat/lib/libexpat.lib \
../../../texk/kpathsea/libkpathsea.lib

SYSLIBS = user32.lib advapi32.lib shell32.lib rpcrt4.lib
all: $(PROGRAM)

$(PROGRAM): $(LLIBS) $(OBJS)
	$(CC) -Fe$@ $(OBJS) $(LLIBS) $(DBG) $(SYSLIBS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $(SRCS)

install: $(PROGRAM)
	cp -p $(PROGRAM) c:/usr/local/txdir/w32tex/bin/
	cp -p $(PROGRAM) c:/usr/work/edrive/wk/dist/XETEX/bin/

clean::
	rm -f *~ *.exe *.obj
