CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = ft_display_file
SOURCES = ft_display_file.c
OBJECTS = $(SOURCES:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJECTS) main.c
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c ft_display_file.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

.PHONY : all clean fclean
