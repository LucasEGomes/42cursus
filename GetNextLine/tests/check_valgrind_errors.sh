#!/bin/bash

VALGRIND_LOGS=$(find log -type f -name *.valgrind)
for VALGRIND_LOG in $VALGRIND_LOGS; do
    RESULT=$(
        cat $VALGRIND_LOG | 
        grep -nE "(lost|reachable|suppressed|ERROR SUMMARY): [1-9][0-9]*" | 
        head -1 | 
        cut -d : -f 1
    )
    if [ ! -z "$RESULT" ]; then
        echo "tests/$VALGRIND_LOG:$RESULT"
    fi
done
