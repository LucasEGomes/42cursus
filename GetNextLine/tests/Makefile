SHELL := /bin/bash
CC := cc
CFLAGS := -Wall -Wextra -Werror
VALGRIND_FLAGS := --leak-check=full -s

SOURCE_PATH := ../src
SOURCE_FILES := get_next_line.c \
				get_next_line_utils.c
SOURCES := $(addprefix $(SOURCE_PATH)/,$(SOURCE_FILES) get_next_line.h)

OBJECTS_PATH := objects
OBJECTS_FILES := $(SOURCE_FILES:%.c=%.o)
OBJECTS := $(addprefix $(OBJECTS_PATH)/,$(OBJECTS_FILES))

TESTS := mandatory_1 mandatory_10 mandatory_100
# stdin file_0 file_1 missing_file folder non_regular_file
# TESTS := $(addprefix mandatory_,$(TESTS))
$(info $(SOURCES))
BUFFER_SIZE := $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
$(eval $(BUFFER_SIZE):;@:)

all : | clean norminette mandatory bonus

norminette : $(SOURCES)
	norminette $^ | grep -v "OK!" > $@
	if [[ -n $$(cat ./norminette) ]]; then\
		echo -e "Failed on norminette\e[31m";\
		cat norminette | sed "s/^/\t/";\
		echo -ne "\e[0m";\
	fi

mandatory : $(TESTS)

mandatory_1 : mandatory.c $(SOURCES)
	$(CC) $(CFLAGS) -I $(SOURCE_PATH) -g -D BUFFER_SIZE=1 $^ -o $@.out
	echo -ne "$@\n\t"
	valgrind $(VALGRIND_FLAGS) --log-file=$@.valgrind ./$@.out mandatory_file_0.md

mandatory_10 : mandatory.c $(SOURCES)
	$(CC) $(CFLAGS) -I $(SOURCE_PATH) -g -D BUFFER_SIZE=10 $^ -o $@.out
	echo -ne "$@\n\t"
	valgrind $(VALGRIND_FLAGS) --log-file=$@.valgrind ./$@.out mandatory_file_0.md

mandatory_100 : mandatory.c $(SOURCES)
	$(CC) $(CFLAGS) -I $(SOURCE_PATH) -g -D BUFFER_SIZE=100 $^ -o $@.out
	echo -ne "$@\n\t"
	valgrind $(VALGRIND_FLAGS) --log-file=$@.valgrind ./$@.out mandatory_file_0.md

# mandatory_file_% : mandatory.out mandatory_file_%.md
# 	./$^

# mandatory_stdin : mandatory.out
# 	./$^

# mandatory_missing_file : mandatory.out
# 	TEST_FILE=file_that_does_not_exist && rm -f $$TEST_FILE && ./$^ $$TEST_FILE

# mandatory_folder : mandatory.out mandatory_test_folder
# 	./$^ $@

# mandatory_non_regular_file : mandatory.out
# 	./$^ /dev/null
# 	./$^ /dev/empty
# 	./$^ /dev/true
# 	./$^ mandatory_symbolic

# mandatory.out : $(OBJECTS) mandatory.c
# 	$(CC) $(CFLAGS) -I $(SOURCE_PATH) -g $^ -o $@

# $(OBJECTS_PATH)/%.o : $(wildcard $(SOURCE_PATH))/%.c
# 	$(CC) $(CFLAGS) -I $(SOURCE_PATH) -D BUFFER_SIZE=1 -c -g $< -o $@

clean :
	rm -rf $(OBJECTS)

# $(OBJECTS) : $(SOURCE_PATH)/get_next_line.h

.PHONY : all mandatory bonus clean norminette
