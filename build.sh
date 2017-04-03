#!/bin/bash
for src in `find . -name "figure*.c" | cut -d"/" -f2`; do
    objname=`echo $src | cut -d"." -f1`
    echo "build... " $src " > " $objname;
    clang $src libapue_core.A.dylib -o $objname;
done
echo "Done"

