#!/bin/sh
cat ../fontconfig/fontconfig.h fcdeprecate.h ../fontconfig/fcprivate.h | grep '^Fc[^ ]* *(' | sed -e 's/ *(.*$//' >names-1.lst
