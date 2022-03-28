#!/bin/sh
FILE_WITHOUT_EXT="${0%.*}"
mkdir -p temp
touch temp/file{1..3}.sh
cp $ROOT_DIR/ex03/find_sh.sh temp/
cd temp
bash find_sh.sh | sort | cat -e > ../$FILE_WITHOUT_EXT.user
cd ..
diff $FILE_WITHOUT_EXT.expected $FILE_WITHOUT_EXT.user > $FILE_WITHOUT_EXT.output
rm -rf temp/
