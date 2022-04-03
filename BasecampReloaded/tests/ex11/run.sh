NO_EXT="${1%.*}"
COMPILED="${NO_EXT}.out"
RESULT="${NO_EXT}.user"
OUTPUT="${NO_EXT}.output"
EXPECTED="${NO_EXT}.expected"
echo -n > $OUTPUT
${CC} ${CFLAGS} $1 ${ROOT_DIR}/ex11/ft_div_mod.c ex11.c -o $COMPILED 2>> $OUTPUT
./$COMPILED > "$RESULT" 2>> $OUTPUT
diff $EXPECTED $RESULT >> $OUTPUT 2>> $OUTPUT
rm -f $COMPILED
