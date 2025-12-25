#!/bin/sh
for i in \
fc-query
do
groff -mandoc -e -t -Tps $i.1 >tmp1.ps
sed 's/Times-Roman/NimbusRomNo9L-Regu/g
s/Times-Bold/NimbusRomNo9L-Medi/g
s/Times-Italic/NimbusRomNo9L-ReguItal/g' <tmp1.ps >$i.ps
distill -Jpressqualitya4 $i.ps
done
rm -f tmp1.ps
