find $1/ -type f \( -name *.o -o -name *.a \) | sort > $3 2>> $2
diff $4 $3 >> $2 2>> $2
