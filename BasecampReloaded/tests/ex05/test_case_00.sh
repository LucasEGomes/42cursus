#!/bin/sh
FILE_WITHOUT_EXT="${0%.*}"
diff $ROOT_DIR/ex05/\"\\\?\$\*\'MaRViN\'\*\$\?\\\" <(echo -n "42") > $FILE_WITHOUT_EXT.output
ls -lRa $ROOT_DIR/ex05/*MaRV* | cat -e | grep -F -v \"\\\?$\*\'MaRViN\'\*$\?\\\"$ >> $FILE_WITHOUT_EXT.output
rm -rf temp/
