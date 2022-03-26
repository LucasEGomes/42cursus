#!/bin/sh
mkdir -p temp
mkdir -p temp/folder
mkdir -p temp/folder\~
mkdir -p temp/\#folder\#
touch temp/folder/\#delete_me{0..5}\#
touch temp/folder/delete_me{0..5}\~
touch temp/folder/do_not_delete_me{0..5}\#
touch temp/folder\~/do_not_delete_me{0..5}
touch temp/\#folder\#/do_not_delete_me{0..5}
cp $ROOT_DIR/ex02/clean temp/
cd temp
bash clean | sort > ../test_case_02.user
cd ..
diff test_case_02.expected test_case_02.user > test_case_02.output
RESULT=$(find temp | wc -l)
if [ -z "$(cat test_case_02.output)" ] && [ "$RESULT" -eq 23 ];
then
    echo -n "O" >> $TEST_SUMMARY
else
    echo -n "X" >> $TEST_SUMMARY
fi
rm -rf temp/
