#!/bin/sh
FILE_WITHOUT_EXT="${0%.*}"
mkdir -p temp
mkdir -p temp/folder
touch temp/.sh
touch temp/find_.sh_me{0..2}.sh
touch temp/find_me{0..2}.sh.sh
touch temp/.find_me{0..2}.sh
touch temp/folder/.sh_find_me{0..2}.sh
touch temp/sh.sh.sh.sh
cp $ROOT_DIR/ex03/find_sh.sh temp/
cd temp
bash find_sh.sh | sort | cat -e > ../$FILE_WITHOUT_EXT.user
cd ..
diff $FILE_WITHOUT_EXT.expected $FILE_WITHOUT_EXT.user > $FILE_WITHOUT_EXT.output
rm -rf temp/
