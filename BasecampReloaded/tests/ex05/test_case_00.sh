#!/bin/sh
diff $ROOT_DIR/ex05/\"\\\?\$\*\'MaRViN\'\*\$\?\\\" <(echo -n "42") > test_case_00.output
ls -lRa $ROOT_DIR/ex05/*MaRV* | cat -e | grep -F -v \"\\\?$\*\'MaRViN\'\*$\?\\\"$ >> test_case_00.output
if [ -z "$(cat test_case_00.output)" ];
then
    echo -n "O" >> $TEST_SUMMARY
else
    echo -n "X" >> $TEST_SUMMARY
fi
rm -rf temp/
