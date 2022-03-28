#!/bin/sh
FILE_WITHOUT_EXT="${0%.*}"
EXPECTED="$(cat $FILE_WITHOUT_EXT.expected)"
RESULT="$(cat $ROOT_DIR/ex01/z)"
diff <(echo -n "$EXPECTED") <(echo -n "$RESULT") > $FILE_WITHOUT_EXT.output
