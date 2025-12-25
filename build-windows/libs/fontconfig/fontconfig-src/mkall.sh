#!/bin/sh
for i in \
fc-cache \
fc-cat \
fc-conflist \
fc-list \
fc-match \
fc-pattern \
fc-query \
fc-scan \
fc-validate
do
(cd $i; rm -f *.obj *.exe *.lib; make)
done
