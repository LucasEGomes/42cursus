export ROOT_DIR = $(shell pwd)
export TEST_SUMMARY = $(ROOT_DIR)/tests/tests.summary
TESTS_DIR = tests
EXERCISES = ex00 ex01 ex02 ex03 ex04 ex05
TEST_CASES = $(wildcard \
				$(addsuffix /test_case_*.sh,\
					$(addprefix $(TESTS_DIR)/,$(EXERCISES))\
				)\
			)
TEST_OUTPUTS = $(TEST_CASES:%.sh=%.output)

check : | $(TEST_SUMMARY) $(TEST_OUTPUTS)
	cat $(TEST_SUMMARY)

$(TEST_SUMMARY) : .FORCE
	echo -n "" > $(TEST_SUMMARY)

%.output : %.sh .FORCE
	echo "$$(basename $$(dirname $@))" >> $(TEST_SUMMARY)
	echo -n "\t$(@:%.output=%) " >> $(TEST_SUMMARY)
	cd $$(dirname $@) && bash $$(basename $<) && cd $(ROOT_DIR)
	echo "" >> $(TEST_SUMMARY)

.FORCE :

.PHONY : check .FORCE
