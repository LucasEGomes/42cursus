#!/bin/sh
EXPECTED="$(cat test_case_00.expected)"
RESULT="$(cat $ROOT_DIR/ex01/z)"
diff <(echo -n "$EXPECTED") <(echo -n "$RESULT") > test_case_00.output
if [ -z "$(cat test_case_00.output)" ];
then
    echo -n "O" >> $TEST_SUMMARY
else
    echo -n "X" >> $TEST_SUMMARY
fi
