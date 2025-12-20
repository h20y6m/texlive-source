top_srcdir = ..
PUBLIC_FILES = \
	$(top_srcdir)/fontconfig/fontconfig.h \
	$(top_srcdir)/src/fcdeprecate.h \
	$(top_srcdir)/fontconfig/fcprivate.h

PUBLIC_FT_FILES = \
	$(top_srcdir)/fontconfig/fcfreetype.h

CFLAGS = -nologo -MT -O2 -W0 -DWIN32=1 -D_WIN32=1 -DXML_STATIC=1 \
-DHAVE_CONFIG_H=1 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE \
-D_CRT_OBSOLETE_NO_DEPRECATE -DNO_KPSE_DLL=1 -DF_OK=0 -wd4819 \
-I. -I.. -I../../freetype/include \
-I../../../texk/kpathsea -I../../../texk -I../../expat/lib

#CFLAGS = -nologo -MT -Od -Zi -W0 -DWIN32=1 -D_WIN32=1 -DXML_STATIC=1 \
#-DHAVE_CONFIG_H=1 -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE \
#-D_CRT_OBSOLETE_NO_DEPRECATE -DNO_KPSE_DLL=1 -DF_OK=0 -wd4819 \
#-I. -I.. -I../../freetype/include \
#-I../../../texk/kpathsea -I../../../texk -I../../expat/lib

OBJECTS = fcatomic.obj fccache.obj \
	fccfg.obj fccharset.obj fccompat.obj fcdbg.obj fcdefault.obj \
	fcdir.obj fcformat.obj fcfreetype.obj fcfs.obj fchash.obj \
	fcinit.obj fclang.obj fclist.obj fcmatch.obj fcmatrix.obj \
	fcname.obj fcobjs.obj fcpat.obj fcptrlist.obj \
	fcrange.obj fcserialize.obj fcstat.obj fcstr.obj fcxml.obj \
	fcweight.obj ftglue.obj

LIBS=
libfontconfig.lib: $(OBJECTS)
	lib -out:$@ $(OBJECTS) $(LIBS)

clean:
	rm -f *~ *.lib *.obj
