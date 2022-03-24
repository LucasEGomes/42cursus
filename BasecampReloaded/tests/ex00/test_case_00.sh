rm -rf temp test_case_00.user
mkdir -p temp
tar -xf $ROOT_DIR/ex00/exo.tar -C temp/
RESULT="$(ls -l temp/)"
while read p;
do
    echo "$RESULT" | grep -E -e "$p" >> test_case_00.user
done < "test_case_00.expected"
diff test_case_00.user <(echo "$RESULT") > test_case_00.output
if [ -z $(cat test_case_00.output) ];
then
    echo -n "O" >> $TEST_SUMMARY
else
    echo -n "X" >> $TEST_SUMMARY
fi
