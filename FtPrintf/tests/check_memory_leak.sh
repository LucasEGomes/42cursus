#!/bin/bash
WIDTH=$(( $2 - 10 ))
if [ -z "$(grep "LEAK SUMMARY:" "$1")" ]; then
    printf "%-${WIDTH}s[\033[1;32m   OK   \033[0m]\n" "valgrind"
else
    printf "%-${WIDTH}s[\033[1;31m FAILED \033[0m]\n" "valgrind"
fi
