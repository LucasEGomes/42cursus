#!/bin/sh
mkdir -p temp
mkdir -p temp/folder
touch temp/.sh
touch temp/find_.sh_me{0..2}.sh
touch temp/find_me{0..2}.sh.sh
touch temp/.find_me{0..2}.sh
touch temp/folder/.sh_find_me{0..2}.sh
touch temp/sh.sh.sh.sh
cp $ROOT_DIR/ex03/find_sh.sh temp/
cd temp
bash find_sh.sh | sort | cat -e > ../test_case_02.user
cd ..
diff test_case_02.expected test_case_02.user > test_case_02.output
if [ -z "$(cat test_case_02.output)" ];
then
    echo -n "O" >> $TEST_SUMMARY
else
    echo -n "X" >> $TEST_SUMMARY
fi
rm -rf temp/
