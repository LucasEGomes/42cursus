TEST_CASES = test_case_00.sh

check : $(TEST_CASES)
	echo -n "\ttest_case_00 " >> $(TEST_SUMMARY)
	bash test_case_00.sh
	echo "" >> $(TEST_SUMMARY)

clean :
	rm -rf temp *.user *.output
