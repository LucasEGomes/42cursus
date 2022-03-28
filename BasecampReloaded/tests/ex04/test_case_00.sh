#!/bin/sh
FILE_WITHOUT_EXT="${0%.*}"
bash $ROOT_DIR/ex04/MAC.sh > test_case_00.user
cat test_case_00.user | grep -E -v "^([0-9a-f]{2}[:]){5}[0-9a-f]{2}$" > $FILE_WITHOUT_EXT.output
while read p;
do
    if [ $(ifconfig -a | grep "$p" | wc -l) -ne 1 ];
    then
        echo "\`$p\` not found." >> $FILE_WITHOUT_EXT.output
    fi
done < "$FILE_WITHOUT_EXT.user"
rm -rf temp/
