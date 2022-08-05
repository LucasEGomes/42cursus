#!/bin/bash
source $(dirname $0)/format.sh
WIDTH=$(( $2 - 10 ))
if [ -z "$(grep "LEAK SUMMARY:" "$1")" ]; then
    printf "%-${WIDTH}s[${FG_BOLD}${FG_GREEN}   OK   ${FONT_RESET}]\n" "valgrind"
else
    printf "%-${WIDTH}s[${FG_BOLD}${FG_RED} FAILED ${FONT_RESET}]\n" "valgrind"
fi
