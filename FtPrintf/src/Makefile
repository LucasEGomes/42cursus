NAME := libftprintf.a

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar -rcs $@ $^

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : | fclean all

.PHONY : all clean fclean re
