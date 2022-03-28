#!/bin/sh
FILE_WITHOUT_EXT="${0%.*}"
mkdir -p temp
mkdir -p temp/folder
mkdir -p temp/folder.sh
touch temp/folder/find_me{0..2}.sh
touch temp/do_not_find_me{0..2}_sh
touch temp/folder/do_not_find_me{0..2}_sh
cp $ROOT_DIR/ex03/find_sh.sh temp/
cd temp
bash find_sh.sh | sort | cat -e > ../$FILE_WITHOUT_EXT.user
cd ..
diff $FILE_WITHOUT_EXT.expected $FILE_WITHOUT_EXT.user > $FILE_WITHOUT_EXT.output
rm -rf temp/
