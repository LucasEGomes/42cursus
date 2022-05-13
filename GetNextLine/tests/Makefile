CC := cc
CFLAGS := -Wall -Wextra -Werror
VALGRIND_FLAGS := --leak-check=yes

SOURCE_PATH := ../src #path to get next line source files
SOURCES := get_next_line.c \
		   get_next_line_utils.c

OBJECTS_PATH := objects
OBJECTS_FILES := $(SOURCES:%.c=%.o)
OBJECTS := $(addprefix $(OBJECTS_PATH)/,$(OBJECTS_FILES))

BUFFER_SIZE := $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
$(eval $(BUFFER_SIZE):;@:)

all : | clean mandatory bonus

mandatory : mandatory.out
	./$<

mandatory.out : $(OBJECTS) mandatory.c
	$(CC) $(CFLAGS) -I $(SOURCE_PATH) -g $^ -o $@

$(OBJECTS_PATH)/%.o : $(wildcard $(SOURCE_PATH))/%.c
	$(CC) $(CFLAGS) -I $(SOURCE_PATH) -c -g $< -o $@

clean :
	rm -rf $(OBJECTS)

# $(OBJECTS) : $(SOURCE_PATH)/get_next_line.h

.PHONY : all mandatory bonus clean
