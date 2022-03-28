#!/bin/sh
FILE_WITHOUT_EXT="${0%.*}"
mkdir -p temp
touch temp/\#delete_me{0..5}\#
touch temp/do_not_delete_me{0..5}\#
touch temp/\#do_not_delete_me{0..5}
touch temp/do_not_delete_me{0..5}
cp $ROOT_DIR/ex02/clean temp/
cd temp
bash clean | sort > ../$FILE_WITHOUT_EXT.user
cd ..
diff $FILE_WITHOUT_EXT.expected $FILE_WITHOUT_EXT.user > $FILE_WITHOUT_EXT.output
RESULT=$(find temp | wc -l)
if [ "$RESULT" -ne 20 ];
then
    echo "$RESULT" >> "$FILE_WITHOUT_EXT.output"
fi
rm -rf temp/
