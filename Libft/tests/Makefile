SHELL := /bin/bash
CC := gcc
CFLAGS := -Wall -Wextra -Werror
TIMEOUT := 15s
LIBFT_FOLDER := $(dir $(CURDIR))src
INCLUDES := -I $(LIBFT_FOLDER) -I $(CURDIR)
SOURCES := ft_isalpha.c \
		   ft_isdigit.c \
		   ft_isalnum.c \
		   ft_isascii.c \
		   ft_isprint.c \
		   ft_strlen.c \
		   ft_memset.c \
		   ft_bzero.c \
		   ft_memcpy.c \
		   ft_memmove.c \
		   ft_strlcpy.c \
		   ft_strlcat.c \
		   ft_toupper.c \
		   ft_tolower.c \
		   ft_strchr.c \
		   ft_strrchr.c \
		   ft_strncmp.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_strnstr.c \
		   ft_atoi.c \
		   ft_calloc.c \
		   ft_strdup.c
_SOURCES := $(wildcard $(addprefix $(LIBFT_FOLDER)/,$(SOURCES)))
FUNCTIONS := $(_SOURCES:$(LIBFT_FOLDER)/%.c=%)
TESTS := $(wildcard $(addsuffix /*.c,$(FUNCTIONS)))
PROGRAMS := $(TESTS:%.c=%.out)

all-tests : $(PROGRAMS)

%.out : %.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ -L $(LIBFT_FOLDER) -lft
	(timeout $(TIMEOUT) ./$@ && echo "$* succeeded.") || echo "$* failed."
	rm -f $@

.SECONDEXPANSION:
$(FUNCTIONS) : $$(filter $$@/%.out,$$(PROGRAMS))

$(TESTS) : $(LIBFT_FOLDER)/libft.a

$(LIBFT_FOLDER)/libft.a : $(_SOURCES)
	make -C $(LIBFT_FOLDER)

.PHONY : $(FUNCTIONS) foo