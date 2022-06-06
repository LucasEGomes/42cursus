SHELL := /bin/bash
CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
VALGRIND_FLAGS := -s --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1
LIBFT_FOLDER := ../libft

FG_RED := \e[0;31m
FG_GREEN := \e[0;32m
FG_YELLOW := \e[0;33m
COLOR_RESET := \e[0;0m

SUBJECT_PATH := ../src

SOURCE_FILES := get_next_line.c \
				get_next_line_utils.c
SOURCE_HEADER := get_next_line.h
SOURCES := $(addprefix $(SUBJECT_PATH)/,$(SOURCE_FILES) $(SOURCE_HEADER))

BONUS_FILES := get_next_line_bonus.c \
			   get_next_line_utils_bonus.c
BONUS_HEADER := get_next_line_bonus.h
BONUSES := $(addprefix $(SUBJECT_PATH)/,$(BONUS_FILES) $(BONUS_HEADER))

TEMP_PATH := temp
LOG_FOLDER := log
MANDATORY_TEMP := test_mandatory
BONUS_TEMP := test_bonus

BUFFER_MAX := 0x7fffffffffffffffL
PROGRESSIVE_BUFFERS := \
		buffer_-10 \
		 buffer_-1 \
		  buffer_0 \
		  buffer_1 \
		 buffer_10 \
		buffer_100 \
	   buffer_1000 \
	  buffer_10000
BUFFERS := buffer_max \
		 $(PROGRESSIVE_BUFFERS)

TEST_UTILS := utils.c check.c
TEST_FILES := $(sort $(wildcard files/test_*)) \
			  files/this_file_does_not_exist \
			  files/this_is_a_folder

USE_LIBFT := -I $(LIBFT_FOLDER) -L $(LIBFT_FOLDER) -lft
MANDATORY_BASENAME := $(TEMP_PATH)/mandatory_
MANDATORY_SOURCES := $(addprefix $(MANDATORY_TEMP)/,$(SOURCE_FILES) $(SOURCE_HEADER))
MANDATORY_TESTS := $(addprefix $(MANDATORY_BASENAME),$(BUFFERS))
MANDATORY_TESTS := $(addsuffix .out,$(MANDATORY_TESTS))
MANDATORY_LOG := $(foreach BUFFER,$(MANDATORY_TESTS:$(TEMP_PATH)/%.out=%), \
	$(addprefix $(LOG_FOLDER)/$(BUFFER)/,$(TEST_FILES:files/%=%)))
MANDATORY_LOG := $(addsuffix .log,$(MANDATORY_LOG))

BONUS_BASENAME := $(TEMP_PATH)/bonus_
BONUS_SOURCES := $(addprefix $(BONUS_TEMP)/,$(BONUS_FILES) $(BONUS_HEADER))
BONUS_TESTS := $(addprefix $(BONUS_BASENAME),$(BUFFERS))
BONUS_TESTS := $(addsuffix .out,$(BONUS_TESTS))
BONUS_LOG := $(foreach BUFFER,$(BONUS_TESTS:$(TEMP_PATH)/%.out=%), \
	$(addprefix $(LOG_FOLDER)/$(BUFFER)/,$(TEST_FILES:files/%=%)))
BONUS_LOG := $(addsuffix .log,$(BONUS_LOG))

LOG_RECIPES := $(addprefix $(LOG_FOLDER)/mandatory_buffer_%/,\
	$(addsuffix .log,$(TEST_FILES:files/%=%)))

mandatory m : | norminette $(MANDATORY_LOG)
bonus b : $(BONUS_LOG)
mandatory bonus m b : $(LOG_FOLDER)
norminette : log/norminette.log
all : | norminette mandatory bonus

clean :
	rm -rf log temp

fclean : clean
	rm -rf test_bonus test_mandatory

$(MANDATORY_SOURCES) : $(SOURCES) | $(MANDATORY_TEMP)
	cp $^ $(MANDATORY_TEMP)/

$(MANDATORY_TESTS) : $(MANDATORY_SOURCES) $(TEST_UTILS) mandatory.c | libft $(TEMP_PATH)
	$(eval BUFFER_SIZE = $(@:$(MANDATORY_BASENAME)buffer_%.out=%))
	$(eval BUFFER_SIZE = $(BUFFER_SIZE:max=$(BUFFER_MAX)))
	$(CC) $(CFLAGS) -I $(MANDATORY_TEMP)/ -I include/ \
		$^ -o $@ -D BUFFER_SIZE=$(BUFFER_SIZE) \
		$(USE_LIBFT)

$(MANDATORY_TEMP) $(BONUS_TEMP) $(TEMP_PATH) $(LOG_FOLDER):
	mkdir -p $@

$(MANDATORY_LOG) : $(MANDATORY_TESTS)
	$(eval TEST_PROGRAM = $(TEMP_PATH)/$(word 2,$(subst /, ,$@)).out)
	$(eval TEST_FILE = $(@:$(dir $@)%.log=%))
	$(eval TEST_FILE = $(addprefix files/,$(TEST_FILE)))
	if [ ! -d $(dir $@) ]; then \
		mkdir -p $(dir $@); \
		echo $(dir $@); \
	fi
	valgrind $(VALGRIND_FLAGS) \
		--log-file=$(@:.log=.valgrind) \
		$(TEST_PROGRAM) \
		$@ \
		$(TEST_FILE) \
		"$$(cat -e $(TEST_FILE) 2>/dev/null)"
	if [[ $$? -eq 1 ]]; then \
		echo -e " | $(FG_RED)valgrind-KO$(COLOR_RESET)"; \
	else \
		echo -e " | $(FG_GREEN)valgrind-OK$(COLOR_RESET)"; \
	fi


$(BONUS_SOURCES) : $(BONUSES) | $(BONUS_TEMP)
	cp $^ $(BONUS_TEMP)/

$(BONUS_TESTS) : $(BONUS_SOURCES) $(TEST_UTILS) bonus.c | libft $(TEMP_PATH)
	$(eval BUFFER_SIZE = $(@:$(BONUS_BASENAME)buffer_%.out=%))
	$(eval BUFFER_SIZE = $(BUFFER_SIZE:max=$(BUFFER_MAX)))
	$(CC) $(CFLAGS) -I $(BONUS_TEMP)/ -I include/ \
		$^ -o $@ -D BUFFER_SIZE=$(BUFFER_SIZE) \
		$(USE_LIBFT)

$(BONUS_LOG) : $(BONUS_TESTS)
	$(eval TEST_PROGRAM = $(TEMP_PATH)/$(word 2,$(subst /, ,$@)).out)
	$(eval TEST_FILE = $(@:$(dir $@)%.log=%))
	$(eval TEST_FILE = $(addprefix files/,$(TEST_FILE)))
	if [ ! -d $(dir $@) ]; then \
		mkdir -p $(dir $@); \
		echo $(dir $@); \
	fi
	valgrind $(VALGRIND_FLAGS) \
		--log-file=$(@:.log=.valgrind) \
		$(TEST_PROGRAM) \
		$@ \
		$(TEST_FILE) \
		"$$(cat -e $(TEST_FILE) 2>/dev/null)"
	if [[ $$? -eq 1 ]]; then \
		echo -e " | $(FG_RED)valgrind-KO$(COLOR_RESET)"; \
	else \
		echo -e " | $(FG_GREEN)valgrind-OK$(COLOR_RESET)"; \
	fi

log/norminette.log : $(SOURCES) $(BONUSES) | $(LOG_FOLDER)
	norminette $^ | grep -v "OK!" > $@ || true
	if [[ -n $$(cat $@) ]]; then\
		echo -e "Failed on norminette\e[31m";\
		cat $@ | sed "s/^/\t/";\
		echo -ne "\e[0m";\
	fi

libft :
	$(MAKE) -C ../libft

.PHONY : mandatory m bonus b all libft clean fclean
