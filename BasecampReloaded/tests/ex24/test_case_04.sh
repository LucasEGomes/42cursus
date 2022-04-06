NO_EXT="${0%.*}"
OUTPUT=${NO_EXT}.output
RESULT=${NO_EXT}.user
EXPECTED=${NO_EXT}.expected
bash setup.sh $NO_EXT $OUTPUT $RESULT
touch $NO_EXT/all
make all -C $NO_EXT/
find $NO_EXT/ -type f \( -name *.o -o -name *.a \) | sort > $RESULT 2>> $OUTPUT
touch $NO_EXT/re
make re -C $NO_EXT/
find $NO_EXT/ -type f \( -name *.o -o -name *.a \) | sort >> $RESULT 2>> $OUTPUT
touch $NO_EXT/clean
make clean -C $NO_EXT/
find $NO_EXT/ -type f \( -name *.o -o -name *.a \) | sort >> $RESULT 2>> $OUTPUT
touch $NO_EXT/fclean
make re -C $NO_EXT/
make fclean -C $NO_EXT/
find $NO_EXT/ -type f \( -name *.o -o -name *.a \) | sort >> $RESULT 2>> $OUTPUT
diff $EXPECTED $RESULT >> $OUTPUT 2>> $OUTPUT
bash tear_down.sh $NO_EXT
