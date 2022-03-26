#!/bin/sh
mkdir -p temp
touch temp/file{1..3}.sh
cp $ROOT_DIR/ex03/find_sh.sh temp/
cd temp
bash find_sh.sh | sort | cat -e > ../test_case_00.user
cd ..
diff test_case_00.expected test_case_00.user > test_case_00.output
if [ -z "$(cat test_case_00.output)" ];
then
    echo -n "O" >> $TEST_SUMMARY
else
    echo -n "X" >> $TEST_SUMMARY
fi
rm -rf temp/
