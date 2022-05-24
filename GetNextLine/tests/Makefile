SHELL := /bin/bash
CC := cc
CFLAGS := -Wall -Wextra -Werror
VALGRIND_FLAGS := --leak-check=full -s

SOURCE_PATH := ../src
SOURCE_FILES := get_next_line.c \
				get_next_line_utils.c
SOURCES := $(addprefix $(SOURCE_PATH)/,$(SOURCE_FILES) get_next_line.h)

TEMP_PATH := temp

PROGRESSIVE_TESTS := mandatory_1 \
					mandatory_10 \
				   mandatory_100 \
				  mandatory_1000 \
				 mandatory_10000
			# 	mandatory_100000 \
			#    mandatory_1000000 \
			#   mandatory_10000000 \
			#  mandatory_100000000
# 	mandatory_1000000000 \
#    mandatory_10000000000

TESTS := max_size \
		 $(PROGRESSIVE_TESTS)

# TESTS := mandatory_10000000000

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

$(PROGRESSIVE_TESTS) : mandatory.c $(SOURCES)
	mkdir -p $(TEMP_PATH)
	$(CC) $(CFLAGS) -I $(SOURCE_PATH) -g -D BUFFER_SIZE=$(@:mandatory_%=%) $^ -o $(TEMP_PATH)/$@.out
	echo -ne "$@\n\t"
	mkdir -p log_valgrind
	valgrind $(VALGRIND_FLAGS) --log-file=log_valgrind/$@ $(TEMP_PATH)/$@.out mandatory_file_0.md

max_size : mandatory.c $(SOURCES)
	mkdir -p $(TEMP_PATH)
	$(CC) $(CFLAGS) -I $(SOURCE_PATH) -g -D BUFFER_SIZE=9223372036854775807 $^ -o $(TEMP_PATH)/$@.out
	echo -ne "$@\n\t"
	mkdir -p log_valgrind
	valgrind $(VALGRIND_FLAGS) --log-file=log_valgrind/$@ $(TEMP_PATH)/$@.out mandatory_file_0.md

clean :
	rm -rf $(TEMP_PATH)
	rm -rf log_valgrind/*

.PHONY : all mandatory bonus clean norminette
