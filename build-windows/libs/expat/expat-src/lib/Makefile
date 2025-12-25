#
# Makefile for libexpat.lib
#
OPTIMIZE = -O2

CC=cl.exe
CFLAGS=-nologo $(OPTIMIZE) -utf-8 -favor:blend -MT -DWIN32=1 -DNDEBUG=1 \
-D_MBCS -D_LIB -D_CRT_SECURE_NO_DEPRECATE -DCOMPILED_FROM_DSP=1

#OBJS=xmlparse.obj xmlrole.obj xmltok.obj xmltok_impl.obj xmltok_ns.obj

OBJS=xmlparse.obj xmlrole.obj xmltok.obj

libexpat.lib: $(OBJS)
	lib -out:$@ $(OBJS)

clean:
	rm *~ *.lib *.obj
