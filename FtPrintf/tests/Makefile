CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
MAKE := make
SHELL := bash

NAME := unit_tests.out
TEMP := temp
LOG_DIR := reports
TERMINAL_WIDTH := 60

REPORT_FILE := $(LOG_DIR)/report.txt
ERRORS_FILE := $(LOG_DIR)/errors.txt
VALGRIND_FILE := $(LOG_DIR)/valgrind.txt

VALGRIND := valgrind
VFLAGS := --leak-check=full \
	--show-leak-kinds=all \
	-s \
	--log-file="$(VALGRIND_FILE)"
	--track-origins=yes

SOURCE := ../src
SOURCE_OBJECT := $(SOURCE)/libftprintf.a

TESTS := logger.c \
	test_conversions.c \
	test_ft_printf_utils.c \
	unit_tests.c
TESTS_OBJECTS := $(TESTS:%.c=$(TEMP)/%.o)

all : $(NAME) $(LOG_DIR)
	$(VALGRIND) $(VFLAGS) ./$< "$(REPORT_FILE)" "$(ERRORS_FILE)" > /dev/null; \
		wait
	scripts/check_memory_leak.sh "$(VALGRIND_FILE)" $(TERMINAL_WIDTH) >> $(REPORT_FILE)
	cat "$(REPORT_FILE)"

$(SOURCE_OBJECT) :
	$(MAKE) -C $(SOURCE)

$(NAME) : $(TESTS_OBJECTS) $(SOURCE_OBJECT)
	$(CC) $(CFLAGS) -I $(SOURCE) -I ./ $^ -o $@ -D TERMINAL_WIDTH=60

$(LOG_DIR) :
	mkdir -p $@

%.o : %.c

$(TEMP)/%.o : %.c %.h
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(SOURCE) -c $< -o $@

clean :
	rm -rf $(TEMP)
	rm -rf $(LOG_DIR)

fclean : clean
	rm -f $(NAME)

re : | fclean all

.PHONY : all clean fclean re $(SOURCE_OBJECT)

# ifndef VERBOSE
# .SILENT :
# endif
