NO_EXT="${1%.*}"
COMPILED="${NO_EXT}.out"
RESULT="${NO_EXT}.user"
OUTPUT="${NO_EXT}.output"
EXPECTED="${NO_EXT}.expected"
echo -n > $OUTPUT
${CC} ${CFLAGS} $1 ${ROOT_DIR}/ex18/ft_print_params.c -o $COMPILED 2>> $OUTPUT
if [ ! -f ${NO_EXT}.input ]
then
    ./$COMPILED > "$RESULT" 2>> $OUTPUT
else
    ./$COMPILED $(cat ${NO_EXT}.input) > "$RESULT" 2>> $OUTPUT
fi
diff $EXPECTED $RESULT >> $OUTPUT 2>> $OUTPUT
rm -f $COMPILED
