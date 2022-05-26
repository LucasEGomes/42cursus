SHELL := /bin/bash
CC := cc
CFLAGS := -Wall -Wextra -Werror -I ../
VALGRIND_LOG := log_valgrind
VALGRIND_FLAGS := --leak-check=full -s

FG_RED := \e[0;31m
FG_GREEN := \e[0;32m
FG_YELLOW := \e[0;33m
COLOR_RESET := \e[0;0m

BUFFER_MAX := 0xfffffffffffffffL
SOURCE_PATH := ../src
SOURCE_FILES := get_next_line.c \
				get_next_line_utils.c
SOURCES := $(addprefix $(SOURCE_PATH)/,$(SOURCE_FILES) get_next_line.h)

TEMP_PATH := temp

PROGRESSIVE_TESTS := buffer_1 \
					buffer_10 \
				   buffer_100 \
				  buffer_1000 \
				 buffer_10000
		# 		buffer_100000 \
		# 	   buffer_1000000 \
		# 	  buffer_10000000 \
		# 	 buffer_100000000 \
		# 	buffer_1000000000 \
		#    buffer_10000000000

TESTS := buffer_max \
		 $(PROGRESSIVE_TESTS)

TEST_FILES := mandatory_file_0.md mandatory_file_1.md
export LOG_FOLDER = ""

# BUFFER_SIZE := $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
# $(eval $(BUFFER_SIZE):;@:)

all : | clean norminette mandatory bonus

norminette : $(SOURCES)
	norminette $^ | grep -v "OK!" > $@
	if [[ -n $$(cat ./norminette) ]]; then\
		echo -e "Failed on norminette\e[31m";\
		cat norminette | sed "s/^/\t/";\
		echo -ne "\e[0m";\
	fi

mandatory : | libft $(TEMP_PATH) $(TEST_FILES)

libft :
	$(MAKE) -C ../libft

$(TEST_FILES) : $(PROGRESSIVE_TESTS) buffer_max
	$(eval LOG_FOLDER=log_$(notdir $(basename $@)))
	mkdir -p $(LOG_FOLDER)
	echo $(notdir $(basename $@))
	for _TEST in $^; do \
		LOG_FILE=$(LOG_FOLDER)/$${_TEST}.log; \
		VALGRIND_FILE=$(LOG_FOLDER)/$${_TEST}.valgrind; \
		touch $${LOG_FILE}; \
		touch $${VALGRIND_FILE}; \
		valgrind $(VALGRIND_FLAGS) --log-file=$${VALGRIND_FILE} \
			$(TEMP_PATH)/$${_TEST}.out $@ "$$(cat -e $@)" $${LOG_FILE}; \
	done
	echo -n $(RESET)

$(TEMP_PATH) :
	mkdir -p $(TEMP_PATH)

$(PROGRESSIVE_TESTS) : mandatory.c $(SOURCES)
	$(CC) $(CFLAGS) -g -D BUFFER_SIZE=$(@:buffer_%=%) $^ -L ../libft -lft \
		-o $(TEMP_PATH)/$@.out

buffer_max : mandatory.c $(SOURCES)
	$(CC) $(CFLAGS) -g -D BUFFER_SIZE=$(BUFFER_MAX) $^ -L ../libft -lft \
		-o $(TEMP_PATH)/$@.out

clean :
	rm -rf log_*/

.PHONY : all mandatory bonus clean norminette $(PROGRESSIVE_TESTS) buffer_max

bar :
	$(eval BUFFER_SIZE=20)

foo : $(PROGRESSIVE_TESTS)
	for test in $^; \
	do \
		echo -n "$${test}-";\
		echo "OK";\
	done
