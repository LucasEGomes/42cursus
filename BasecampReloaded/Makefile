export CC = gcc
export CFLAGS = -Wall -Wextra -Werror
export ROOT_DIR = $(shell pwd)
TESTS_DIR = tests
EXERCISES = ex00 ex01 ex02 ex03 ex04 ex05 ex06 ex07 ex08 ex09 ex10 ex11 ex12\
			ex13 ex14 ex15 ex16 ex17 ex18 ex19 ex20 ex21 ex22 ex23 ex24 ex25\
			ex26 ex27
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
	rm -rf tests/*/*.output tests/*/*.user

.PHONY : clean check $(EXERCISES) $(C_TESTS) $(SHELL_TESTS)

foo : bar
	# echo ""

bar :
	echo ""