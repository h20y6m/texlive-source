#!/bin/sh
for i in fc-cache \
fc-cat \
fc-conflist \
fc-list \
fc-match \
fc-pattern \
fc-query \
fc-scan \
fc-validate
do
print "(cd $i; cp -p *.exe c:/usr/work/edrive/wk/w64dist/XETEX/bin64/; cp -p *.exe c:/usr/local/txdir/w32tex/bin64/)"
(cd $i; cp -p *.exe c:/usr/work/edrive/wk/w64dist/XETEX/bin64/; cp -p *.exe c:/usr/local/txdir/w32tex/bin64/)
done
