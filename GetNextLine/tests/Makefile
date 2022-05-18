CC := cc
CFLAGS := -Wall -Wextra -Werror
VALGRIND_FLAGS := --leak-check=yes

SOURCE_PATH := ../src #path to get next line source files
SOURCES := get_next_line.c \
		   get_next_line_utils.c

OBJECTS_PATH := objects
OBJECTS_FILES := $(SOURCES:%.c=%.o)
OBJECTS := $(addprefix $(OBJECTS_PATH)/,$(OBJECTS_FILES))

TESTS := mandatory_1
# stdin file_0 file_1 missing_file folder non_regular_file
# TESTS := $(addprefix mandatory_,$(TESTS))

BUFFER_SIZE := $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
$(eval $(BUFFER_SIZE):;@:)

all : | clean mandatory bonus

mandatory : $(TESTS)

mandatory_1 : mandatory.c $(OBJECTS)
	$(CC) $(CFLAGS) -I $(SOURCE_PATH) -g -D BUFFER_SIZE=1 $^ -o $@.out
	./$@.out mandatory_file_0.md

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

$(OBJECTS_PATH)/%.o : $(wildcard $(SOURCE_PATH))/%.c
	$(CC) $(CFLAGS) -I $(SOURCE_PATH) -D BUFFER_SIZE=1 -c -g $< -o $@

clean :
	rm -rf $(OBJECTS)

# $(OBJECTS) : $(SOURCE_PATH)/get_next_line.h

.PHONY : all mandatory bonus clean
