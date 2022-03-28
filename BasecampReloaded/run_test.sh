run_test()
{
    if [ -z "$(cat $1)" ];
    then
        echo "0"
    else
        echo "1"
    fi
}
