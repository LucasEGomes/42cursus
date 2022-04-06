NO_EXT="${0%.*}"
OUTPUT=${NO_EXT}.output
RESULT=${NO_EXT}.user
EXPECTED=${NO_EXT}.expected
bash setup.sh $NO_EXT $OUTPUT $RESULT
touch $NO_EXT/*.o
touch $NO_EXT/*.a
INITIAL_STATE="$(ls ${NO_EXT} --full-time)"
INITIAL_LINES="$(ls ${NO_EXT} --full-time | wc -l)"
make all -C $NO_EXT/
if [[ $INITIAL_STATE != "$(ls ${NO_EXT} --full-time)" ]] || [[ $INITIAL_LINES -ne "$(ls ${NO_EXT} --full-time | wc -l)" ]]
then
    echo "Make all changed state" >> $OUTPUT
fi
make re -C $NO_EXT/ 2>> $OUTPUT
if [[ $INITIAL_STATE == "$(ls ${NO_EXT} --full-time)" ]] || [[ $INITIAL_LINES -ne "$(ls ${NO_EXT} --full-time | wc -l)" ]]
then
    echo "Make re did not changed state" >> $OUTPUT
fi
CHECK_FILE="$(cat ${NO_EXT}/ft_putchar.o | tr -d '\0')"
if [[ "$CHECK_FILE" == "1234fj98j-098" ]]
then
    echo "Make re did not create a new object" >> $OUTPUT
fi
bash assert.sh $NO_EXT $OUTPUT $RESULT $EXPECTED
bash tear_down.sh $NO_EXT
