CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
MAKE := make
SHELL := bash

NAME := unit_tests.out
TEMP := temp
REPORT_DIR := reports

VALGRIND := valgrind
VFLAGS := --leak-check=full \
	--show-leak-kinds=all \
	--suppressions=./munit.supp \
	-s \
	--log-file="$(REPORT_DIR)/valgrind"
	--track-origins=yes

SOURCE := ../src
SOURCE_OBJECT := $(SOURCE)/libftprintf.a

MUNIT := munit
MUNIT_OBJECT := $(TEMP)/munit.o

TESTS := test_conversions.c \
	unit_tests.c
TESTS_OBJECTS := $(TESTS:%.c=$(TEMP)/%.o)

all : $(NAME) $(REPORT_DIR)
	$(VALGRIND) $(VFLAGS) ./$< --color always --log-fatal error \
		2> $(REPORT_DIR)/errors | tee $(REPORT_DIR)/unit_tests

$(SOURCE_OBJECT) :
	$(MAKE) -C $(SOURCE)

$(NAME) : $(TESTS_OBJECTS) $(MUNIT_OBJECT) $(SOURCE_OBJECT)
	$(CC) $(CFLAGS) -I $(SOURCE) -I ./ $^ -o $@

$(REPORT_DIR) :
	mkdir -p $@

%.o : %.c

$(TEMP)/%.o : %.c %.h
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(SOURCE) -c $< -o $@

$(MUNIT) :
	git clone https://github.com/nemequ/munit.git $@

$(MUNIT_OBJECT) : $(MUNIT)
	$(CC) -Wall -Wextra -Werror -I $< -c $</munit.c -o $@

clean :
	rm -rf $(TEMP)

fclean : clean
	rm -f $(NAME)

re : | fclean all

.PHONY : all clean fclean re $(SOURCE_OBJECT)

# ifndef VERBOSE
# .SILENT :
# endif
