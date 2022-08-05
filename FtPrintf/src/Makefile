CC := cc
CFLAGS := -Wall -Wextra -Werror -I ./ -g3
MAKE := make
SHELL := bash

LIBFT := libft
LIBFT_OBJECT := $(LIBFT)/libft.a
LIBFT_HEADER := $(LIBFT:%.a=%.h)

NAME := libftprintf.a
TEMP := temp

SOURCES := ft_printf/conversions.c \
	ft_printf/ft_printf_utils.c \
	ft_printf/ft_printf.c
HEADERS := $(OBJECTS:%.c=%.h)
OBJECTS := $(SOURCES:%.c=temp/%.o)

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT_OBJECT) libftprintf.h
	cp $(LIBFT_OBJECT) $@
	ar -rcs $@ $(OBJECTS)

$(OBJECTS) : $(LIBFT_HEADER)

$(LIBFT) :
	git clone https://github.com/LucasEGomes/libft --branch GNL $@

$(LIBFT_OBJECT) : | $(LIBFT)
	$(MAKE) -C $(LIBFT)

%.o : %.c


$(TEMP)/%.o : %.c %.h
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -L $(LIBFT) -lft

clean :
	rm -rf $(TEMP)

fclean : clean
	rm -f $(NAME)

re : | fclean all

.PHONY : all clean fclean re

# ifndef VERBOSE
# .SILENT :
# endif
