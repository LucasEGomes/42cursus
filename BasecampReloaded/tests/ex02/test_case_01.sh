#!/bin/sh
mkdir -p temp
touch temp/\#delete_me{0..5}\#
touch temp/do_not_delete_me{0..5}\#
touch temp/\#do_not_delete_me{0..5}
touch temp/do_not_delete_me{0..5}
cp $ROOT_DIR/ex02/clean temp/
cd temp
bash clean | sort > ../test_case_01.user
cd ..
diff test_case_01.expected test_case_01.user > test_case_01.output
RESULT=$(find temp | wc -l)
if [ -z "$(cat test_case_01.output)" ] && [ "$RESULT" -eq 20 ];
then
    echo -n "O" >> $TEST_SUMMARY
else
    echo -n "X" >> $TEST_SUMMARY
fi
rm -rf temp/
