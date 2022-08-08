CC := cc
CFLAGS := -Wall -Wextra -Werror -I ./ -g3
MAKE := make
SHELL := bash

LIBFT := libft
LIBFT_OBJECT := $(LIBFT)/libft.a
LIBFT_HEADER := $(LIBFT:%.a=%.h)

NAME := libftprintf.a
TEMP := temp

CONVERSIONS = ft_printf/conversions/find_conversions.c \
	ft_printf/conversions/hexadecimals.c \
	ft_printf/conversions/integers.c \
	ft_printf/conversions/pointers.c \
	ft_printf/conversions/texts.c \
	ft_printf/conversions/unsigned_integers.c
SOURCES := ft_printf/ft_printf.c \
	ft_printf/ft_printf_utils.c \
	$(CONVERSIONS)
OBJECTS := $(SOURCES:%.c=temp/%.o)

all : $(NAME)

$(NAME) : $(LIBFT_OBJECT) $(OBJECTS) libftprintf.h
	cp $(LIBFT_OBJECT) $@
	ar -rcs $@ $(OBJECTS)

$(OBJECTS) : $(LIBFT_HEADER)

$(LIBFT) :
	git clone https://github.com/LucasEGomes/libft --branch GNL $@

$(LIBFT_OBJECT) : | $(LIBFT)
	$(MAKE) -C $(LIBFT)

%.o : %.c
	;

$(TEMP)/%.o : %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) -C $(LIBFT) clean
	rm -rf $(TEMP)

fclean : clean
	$(MAKE) -C $(LIBFT) fclean
	sleep 1s
	rm -f $(NAME)

re : | fclean all

.PHONY : all clean fclean re
