NAME := so_long
CC := gcc
CFLAGS := -Wall -Wextra -Werror
ifdef SO_LONG_DEBUG
CFLAGS += -g3
else
CFLAGS += -O2
endif
MLX := minilibx-linux
MLX_NAME := libmlx.a
MLX_LIBRARY := $(MLX)/$(MLX_NAME)
INCLUDES := -I $(MLX)
LIBRARIES := -L . -lmlx -lXext -lX11
SOURCES := \
	assets.c \
	exceptions.c \
	free_resources.c \
	game.c \
	gui.c \
	main.c \
	map.c \
	print_utils.c \
	string_utils.c \
	validators.c
OBJECTS_FOLDER := objects
OBJECTS := $(SOURCES:%.c=$(OBJECTS_FOLDER)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS_FOLDER) $(OBJECTS) $(MLX_NAME) 
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LIBRARIES) -o $@

$(OBJECTS_FOLDER):
	mkdir -p $@

$(OBJECTS_FOLDER)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX_NAME): $(MLX_LIBRARY)
	cp $< .

clean:
	$(MAKE) -C $(MLX) clean
	rm -rf $(OBJECTS_FOLDER)
	rm -f $(MLX_NAME)

fclean: clean
	rm -f $(NAME)

re: | fclean all

$(MLX_LIBRARY): $(MLX)
	$(MAKE) -C $< -s

$(MLX):
	git clone https://github.com/42Paris/minilibx-linux $@

norminette_errors:
	norminette *.c *.h | grep -v OK! > $@ || true
	cat $@

.PHONY: all clean fclean all norminette_errors
