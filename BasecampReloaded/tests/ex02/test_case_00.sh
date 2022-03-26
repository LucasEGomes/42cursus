#!/bin/sh
mkdir -p temp
touch temp/delete_me~
cp $ROOT_DIR/ex02/clean temp/
cd temp
bash clean | sort > ../test_case_00.user
cd ..
diff test_case_00.expected test_case_00.user > test_case_00.output
RESULT=$(find temp | wc -l)
if [ -z "$(cat test_case_00.output)" ] && [ "$RESULT" -eq 2 ];
then
    echo -n "O" >> $TEST_SUMMARY
else
    echo -n "X" >> $TEST_SUMMARY
fi
rm -rf temp/
