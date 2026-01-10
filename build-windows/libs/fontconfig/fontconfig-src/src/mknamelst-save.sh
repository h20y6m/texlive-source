#!/bin/sh
cat ../fontconfig/fontconfig.h ../fontconfig/fcfreetype.h ../src/fcdeprecate.h ../fontconfig/fcprivate.h | grep '^Fc[^ ]* *(' | sed -e 's/ *(.*$//' >names.lst
