NO_EXT="${0%.*}"
OUTPUT=${NO_EXT}.output
RESULT=${NO_EXT}.user
EXPECTED=${NO_EXT}.expected
bash setup.sh $NO_EXT $OUTPUT $RESULT
make fclean -C $NO_EXT/ 2>> $OUTPUT
bash assert.sh $NO_EXT $OUTPUT $RESULT $EXPECTED
bash tear_down.sh $NO_EXT
