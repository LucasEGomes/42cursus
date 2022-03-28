source run_test.sh

PERCENT_COL=74
DEFAULT="\e[0m"
GREEN="\e[32m"
RED="\e[31m"
TEST_CASES=$(ls -1 tests/$1 | grep -E "^test_case_[0-9]{2}[.]output$" | sort)
if [ -z $(echo "$TEST_CASES" | tr -d '\n') ];
then
    exit
fi
TESTS=$(echo "$TEST_CASES" | wc -l )
FAILED=0
echo -n "$1 "
for TEST_CASE in $TEST_CASES;
do
    RESULT=$(run_test "tests/$1/$TEST_CASE")
    echo -en "$GREEN"
    if [ $RESULT -ne 0 ];
    then
        FAILED=$[ $FAILED + 1 ]
        echo -en "${RED}X"
    else
        echo -en "${GREEN}O"
    fi
done
echo -en "$GREEN"
if [ $FAILED -gt 0 ];
then
    echo -en "$RED"
fi
RATE=$[ ( $TESTS - $FAILED ) * 100 / $TESTS ]
PADDING=$[ $PERCENT_COL - 5 - $TESTS ]
printf "%*s[%*d%%]" $PADDING ' ' 3 $RATE
echo -e "$DEFAULT"