NO_EXT="${1%.*}"
COMPILED="${NO_EXT}.out"
RESULT="${NO_EXT}.user"
OUTPUT="${NO_EXT}.output"
EXPECTED="${NO_EXT}.expected"
echo -n > $OUTPUT
${CC} ${CFLAGS} -Wl,--wrap=malloc $1 ${ROOT_DIR}/ex21/ft_range.c ex21.c -o $COMPILED 2>> $OUTPUT
./$COMPILED > "$RESULT" 2>> $OUTPUT
diff $EXPECTED $RESULT >> $OUTPUT 2>> $OUTPUT
rm -f $COMPILED
