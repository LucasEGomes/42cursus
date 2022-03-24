export ROOT_DIR = $(shell pwd)
export TEST_SUMMARY = $(ROOT_DIR)/tests/tests.summary
TESTS_DIR = tests
EXERCISES = ex00

ex00 : ex00/exo.tar
	@echo -n "" > $(TEST_SUMMARY)
	$(MAKE) -C $(TESTS_DIR)/$@ check
	@cat $(TEST_SUMMARY)

check : $(EXERCISES)

.PHONY : $(EXERCISES) check
