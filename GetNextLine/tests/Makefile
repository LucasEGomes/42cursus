SHELL := /bin/bash
CC := cc
CFLAGS := -Wall -Wextra -Werror -g3 
VALGRIND_LOG := log_valgrind
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all -s --track-origins=yes --error-exitcode=1

FG_RED := \e[0;31m
FG_GREEN := \e[0;32m
FG_YELLOW := \e[0;33m
COLOR_RESET := \e[0;0m

SUBJECT_PATH := ../src
SOURCE_FILES := get_next_line.c \
				get_next_line_utils.c
SOURCES := $(addprefix $(SUBJECT_PATH)/,$(SOURCE_FILES))

BONUS_FILES := get_next_line_bonus.c \
			   get_next_line_utils_bonus.c
BONUSES := $(addprefix $(SUBJECT_PATH)/,$(BONUS_FILES))

TEST_SOURCES := utils.c check.c

TEMP_PATH := temp
BUFFER_MAX := 0x7fffffffffffffffL
PROGRESSIVE_BUFFERS := \
					buffer_-1 \
					 buffer_1 \
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
BONUS_PROGRESSIVE_BUFFERS := $(addprefix bonus_,$(PROGRESSIVE_BUFFERS))
BUFFERS := buffer_max \
		 $(PROGRESSIVE_BUFFERS)
BONUS_BUFFERS := $(addprefix bonus_,$(BUFFERS))
TEST_FILES := $(sort $(wildcard files/test_*)) \
			  files/this_file_does_not_exist \
			  files/this_is_a_folder


LOG_FOLDER = log
export LOG_TEST = ""

# BUFFER_SIZE := $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
# $(eval $(BUFFER_SIZE):;@:)

all : | clean mandatory bonus log/norminette

log/norminette : $(SOURCES) $(BONUS_SOURCES)
	norminette $^ | grep -v "OK!" > $@ || true
	if [[ -n $$(cat $@) ]]; then\
		echo -e "Failed on norminette\e[31m";\
		cat $@ | sed "s/^/\t/";\
		echo -ne "\e[0m";\
	fi

mandatory : | libft $(TEMP_PATH) $(LOG_FOLDER) $(TEST_FILES) test_alice_in_wonderland

libft :
	$(MAKE) -C ../libft

$(TEST_FILES) : $(PROGRESSIVE_BUFFERS) buffer_max | program_per_buffer
	$(eval LOG_TEST=$(LOG_FOLDER)/$(notdir $(basename $@)))
	mkdir -p $(LOG_TEST)
	echo $(notdir $(basename $@))
	for _TEST in $^; do \
		LOG_FILE=$(LOG_TEST)/$${_TEST}.log; \
		VALGRIND_FILE=$(LOG_TEST)/$${_TEST}.valgrind; \
		touch $${LOG_FILE}; \
		touch $${VALGRIND_FILE}; \
		valgrind $(VALGRIND_FLAGS) --log-file=$${VALGRIND_FILE} \
			$(TEMP_PATH)/$${_TEST}.out $@ "$$(cat -e $@ 2>/dev/null)" $${LOG_FILE}; \
		if [[ $$? -eq 1 ]]; then \
			echo -e " | $(FG_RED)valgrind-KO$(COLOR_RESET)"; \
		else \
			echo -e " | $(FG_GREEN)valgrind-OK$(COLOR_RESET)"; \
		fi; \
	done
	echo -n $(RESET)

program_per_buffer : $(PROGRESSIVE_BUFFERS) buffer_max | mandatory.c
	for _TEST in $^; do \
		$(CC) $(CFLAGS) -I ../ mandatory.c $(TEST_SOURCES) \
			$(TEMP_PATH)/$${_TEST}.o $(TEMP_PATH)/$${_TEST}_utils.o \
			-L ../libft -lft \
			-o $(TEMP_PATH)/$${_TEST}.out; \
	done

test_alice_in_wonderland : $(PROGRESSIVE_BUFFERS) buffer_max | test_alice_in_wonderland.c
	$(eval LOG_TEST=$(LOG_FOLDER)/$@)
	mkdir -p $(LOG_TEST)
	echo $(notdir $(basename $@))
	for _TEST in $^; do \
		LOG_FILE=$(LOG_TEST)/$${_TEST}.log; \
		VALGRIND_FILE=$(LOG_TEST)/$${_TEST}.valgrind; \
		touch $${LOG_FILE}; \
		touch $${VALGRIND_FILE}; \
		$(CC) $(CFLAGS) -I ../ $@.c $(TEST_SOURCES) \
			$(TEMP_PATH)/$${_TEST}.o $(TEMP_PATH)/$${_TEST}_utils.o \
			-L ../libft -lft \
			-o $(TEMP_PATH)/alice_$${_TEST}.out; \
		valgrind $(VALGRIND_FLAGS) --log-file=$${VALGRIND_FILE} \
			$(TEMP_PATH)/alice_$${_TEST}.out $${LOG_FILE}; \
		if [[ $$? -eq 1 ]]; then \
			echo -e " | $(FG_RED)valgrind-KO$(COLOR_RESET)"; \
		else \
			echo -e " | $(FG_GREEN)valgrind-OK$(COLOR_RESET)"; \
		fi; \
	done
	echo -n $(RESET)

bonus : $(BONUS_PROGRESSIVE_BUFFERS) bonus_buffer_max
	$(eval LOG_TEST=$(LOG_FOLDER)/$@)
	mkdir -p $(LOG_TEST)
	echo $(notdir $(basename $@))
	for _TEST in $^; do \
		LOG_FILE=$(LOG_TEST)/$${_TEST}.log; \
		VALGRIND_FILE=$(LOG_TEST)/$${_TEST}.valgrind; \
		touch $${LOG_FILE}; \
		touch $${VALGRIND_FILE}; \
		$(CC) $(CFLAGS) -I ../ $@.c $(TEST_SOURCES) \
			$(TEMP_PATH)/$${_TEST}.o $(TEMP_PATH)/$${_TEST}_utils.o \
			-L ../libft -lft \
			-o $(TEMP_PATH)/$${_TEST}.out; \
		valgrind $(VALGRIND_FLAGS) --log-file=$${VALGRIND_FILE} \
			$(TEMP_PATH)/$${_TEST}.out \
			$${LOG_FILE} \
			files/test_file_00 \
			"$$(cat -e files/test_file_00 2>/dev/null)" \
			files/test_file_01 \
			"$$(cat -e files/test_file_01 2>/dev/null)"; \
		if [[ $$? -eq 1 ]]; then \
			echo -e " | $(FG_RED)valgrind-KO$(COLOR_RESET)"; \
		else \
			echo -e " | $(FG_GREEN)valgrind-OK$(COLOR_RESET)"; \
		fi; \
	done
	echo -n $(RESET)

$(TEMP_PATH) :
	mkdir -p $(TEMP_PATH)

$(LOG_FOLDER) :
	mkdir -p $@

include_mandatory/get_next_line.h : $(SUBJECT_PATH)/get_next_line.h
	mkdir -p include_mandatory
	cp $< ./include_mandatory

$(PROGRESSIVE_BUFFERS) : $(SOURCES) | include_mandatory/get_next_line.h
	$(CC) $(CFLAGS) -I ./include_mandatory -D BUFFER_SIZE=$(@:buffer_%=%) -c $(word 1,$^) \
		-o $(TEMP_PATH)/$@.o
	$(CC) $(CFLAGS) -I ./include_mandatory -D BUFFER_SIZE=$(@:buffer_%=%) -c $(word 2,$^) \
		-o $(TEMP_PATH)/$@_utils.o

buffer_max : $(SOURCES) | include_mandatory/get_next_line.h
	$(CC) $(CFLAGS) -I ./include_mandatory -D BUFFER_SIZE=$(BUFFER_MAX) -c $(word 1,$^) \
		-o $(TEMP_PATH)/$@.o
	$(CC) $(CFLAGS) -I ./include_mandatory -D BUFFER_SIZE=$(BUFFER_MAX) -c $(word 2,$^) \
		-o $(TEMP_PATH)/$@_utils.o

include_bonus/get_next_line_bonus.h : $(SUBJECT_PATH)/get_next_line_bonus.h
	mkdir -p include_bonus
	cp $< ./include_bonus

$(BONUS_PROGRESSIVE_BUFFERS) : $(BONUSES) | include_bonus/get_next_line_bonus.h
	$(CC) $(CFLAGS) -I ./include_bonus -D BUFFER_SIZE=$(@:bonus_buffer_%=%) -c $(word 1,$^) \
		-o $(TEMP_PATH)/$@.o
	$(CC) $(CFLAGS) -I ./include_bonus -D BUFFER_SIZE=$(@:bonus_buffer_%=%) -c $(word 2,$^) \
		-o $(TEMP_PATH)/$@_utils.o

bonus_buffer_max : $(BONUSES) | include_bonus/get_next_line_bonus.h
	$(CC) $(CFLAGS) -I ./include_bonus -D BUFFER_SIZE=$(BUFFER_MAX) -c $(word 1,$^) \
		-o $(TEMP_PATH)/$@.o
	$(CC) $(CFLAGS) -I ./include_bonus -D BUFFER_SIZE=$(BUFFER_MAX) -c $(word 2,$^) \
		-o $(TEMP_PATH)/$@_utils.o

clean :
	rm -rf log*/
	rm -rf temp/

.PHONY : all mandatory bonus clean log/norminette $(PROGRESSIVE_BUFFERS) buffer_max

foo : $(SOURCES)
	echo $(word 1,$^)
	echo $(word 2,$^)