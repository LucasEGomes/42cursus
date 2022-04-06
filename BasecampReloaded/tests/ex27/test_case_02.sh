NO_EXT="${0%.*}"
OUTPUT=${NO_EXT}.output
RESULT=${NO_EXT}.user
EXPECTED=${NO_EXT}.expected
mkdir $NO_EXT/
cp -r $ROOT_DIR/ex27/* $NO_EXT/
echo -n > $RESULT
echo -n > $OUTPUT
find $NO_EXT/ -type f -name ft_display_file | sort >> $RESULT 2>> $OUTPUT
make all -C $NO_EXT/ 2>> $OUTPUT
find $NO_EXT/ -type f -name ft_display_file | sort >> $RESULT 2>> $OUTPUT
$NO_EXT/ft_display_file "Hello" "There" >> $RESULT 2>> $OUTPUT
$NO_EXT/ft_display_file "Hello" "There" "General" "Kenobi" >> $RESULT 2>> $OUTPUT
make clean -C $NO_EXT/ 2>> $OUTPUT
find $NO_EXT/ -type f -name *.o | sort >> $RESULT 2>> $OUTPUT
make fclean -C $NO_EXT/ 2>> $OUTPUT
find $NO_EXT/ -type f -name ft_display_file | sort >> $RESULT 2>> $OUTPUT
make all -C $NO_EXT/ 2>> $OUTPUT
make fclean -C $NO_EXT/ 2>> $OUTPUT
find $NO_EXT/ -type f -name ft_display_file | sort >> $RESULT 2>> $OUTPUT
bash assert.sh $NO_EXT $OUTPUT $RESULT $EXPECTED
bash tear_down.sh $NO_EXT
