#!/bin/sh
bash $ROOT_DIR/ex04/MAC.sh > test_case_00.user
cat test_case_00.user | grep -E -v "^([0-9a-f]{2}[:]){5}[0-9a-f]{2}$" > test_case_00.output
while read p;
do
    if [ $(ifconfig -a | grep "$p" | wc -l) -ne 1 ];
    then
        echo "\`$p\` not found." >> test_case_00.output
    fi
done < "test_case_00.user"
if [ $(cat test_case_00.output | wc -l) -eq 0 ];
then
    echo -n "O" >> $TEST_SUMMARY
else
    echo -n "X" >> $TEST_SUMMARY
fi
rm -rf temp/
