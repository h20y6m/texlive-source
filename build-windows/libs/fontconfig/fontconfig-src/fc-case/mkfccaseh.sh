#!/bin/sh
TARG=fccase.h
TMPL=fccase.tmpl.h
SCASE=./CaseFolding.txt
./fc-case $SCASE <$TMPL >$TARG
