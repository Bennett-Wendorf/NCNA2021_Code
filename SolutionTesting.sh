#!/bin/bash

CODE_NAME="Concert"
PROBELM_NAME="concertrehearsal"
OUTFILE_NAME="tmp.out"

javac $CODE_NAME.java

for filename in NCNA_2021/$PROBELM_NAME/data/secret/*.in; do
    [ -e "$filename" ] || continue
    echo "Testing file: $filename"
    java $CODE_NAME < $filename > tmp.out
    diff tmp.out ${filename::-3}.ans
done

## CLEANUP ##
rm $OUTFILE_NAME
rm $CODE_NAME.class