#!/bin/sh
mkdir -p temp
mkdir -p temp/folder
mkdir -p temp/folder.sh
touch temp/folder/find_me{0..2}.sh
touch temp/do_not_find_me{0..2}_sh
touch temp/folder/do_not_find_me{0..2}_sh
cp $ROOT_DIR/ex03/find_sh.sh temp/
cd temp
bash find_sh.sh | sort | cat -e > ../test_case_01.user
cd ..
diff test_case_01.expected test_case_01.user > test_case_01.output
if [ -z "$(cat test_case_01.output)" ];
then
    echo -n "O" >> $TEST_SUMMARY
else
    echo -n "X" >> $TEST_SUMMARY
fi
rm -rf temp/
