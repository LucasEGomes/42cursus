export ROOT_DIR = $(shell pwd)
export TEST_SUMMARY = $(ROOT_DIR)/tests/tests.summary
TESTS_DIR = tests
EXERCISES = ex00 ex01

$(TEST_SUMMARY) :
	echo -n "" > $(TEST_SUMMARY)

$(EXERCISES) : $(TEST_SUMMARY)
	echo "$@" >> $(TEST_SUMMARY)
	$(MAKE) -C $(TESTS_DIR)/$@ check

check : $(EXERCISES)
	cat $(TEST_SUMMARY)

.PHONY : $(EXERCISES) check $(TEST_SUMMARY)
