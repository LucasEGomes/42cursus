export CC = gcc
export CFLAGS = -Wall -Wextra -Werror
export ROOT_DIR = $(shell pwd)
TESTS_DIR = tests
EXERCISES = ex00 ex01 ex02 ex03 ex04 ex05 ex06 ex07
SHELL_TESTS = $(wildcard $(TESTS_DIR)/*/test_case_*.sh)
C_TESTS = $(wildcard $(TESTS_DIR)/*/test_case_*.c)
.SECONDEXPANSION :

check : $(EXERCISES)

$(EXERCISES) : $(TESTS_DIR)/$$(@)/test_case_*.sh $(TESTS_DIR)/$$(@)/test_case_*.c
	bash summary.sh $@

$(C_TESTS) :
	cd $(@D) && bash run.sh $(@F)

$(SHELL_TESTS) :
	cd $(@D) && bash $(@F)

%*.c %*.sh:
	@

clean :
	rm -rf tests/*/*.output

.PHONY : check $(EXERCISES) $(C_TESTS) $(SHELL_TESTS)
