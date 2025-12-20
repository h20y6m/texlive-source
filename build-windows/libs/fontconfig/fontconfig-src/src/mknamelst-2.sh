#!/bin/sh
cat ../fontconfig/fcfreetype.h | grep '^Fc[^ ]* *(' | sed -e 's/ *(.*$//' >names-2.lst
