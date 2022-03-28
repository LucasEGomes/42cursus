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

check : | $(TEST_OUTPUTS) $(EXERCISES)

%.output : %.sh .FORCE
	cd $$(dirname $@) && bash $$(basename $<) && cd $(ROOT_DIR)

ex% : $(TESTS_DIR)/ex%/test_case_*.output .FORCE
	bash summary.sh $@

.FORCE :

.PHONY : check .FORCE
