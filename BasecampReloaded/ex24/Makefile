CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SOURCES = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
SOURCE_DIR = srcs
INCLUDE_DIR = includes
OBJECTS = $(SOURCES:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar -rcs $(NAME) $^

%.o : $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : | fclean all

.PHONY : all clean fclean re