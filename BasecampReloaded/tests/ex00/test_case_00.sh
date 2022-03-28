#!/bin/sh
FILE_WITHOUT_EXT="${0%.*}"
rm -rf temp "$FILE_WITHOUT_EXT.user"
mkdir -p temp
tar -xf $ROOT_DIR/ex00/exo.tar -C temp/
RESULT="$(ls -l temp/)"
while read p;
do
    echo "$RESULT" | grep -E -e "$p" >> "$FILE_WITHOUT_EXT.user"
done < "$FILE_WITHOUT_EXT.expected"
diff "$FILE_WITHOUT_EXT.user" <(echo "$RESULT") > "$FILE_WITHOUT_EXT.output"
rm -rf temp