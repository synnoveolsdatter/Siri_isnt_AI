#!/bin/bash
for file in `ls ./*.c`; do
    gcc $file -o {file/.c/} -Wall -Wpedantic
done
echo ""
echo "Done"
