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
	a_star.c \
	assets.c \
	double_list.c \
	exceptions.c \
	file_utils.c \
	free_resources.c \
	game.c \
	gui.c \
	main.c \
	map.c \
	map_validators.c \
	player_move.c \
	print_utils.c \
	render.c \
	string_utils.c \
	validators.c
OBJECTS_FOLDER := objects
OBJECTS := $(SOURCES:%.c=$(OBJECTS_FOLDER)/%.o)

MAP_FOLDER := maps
MAPS := $(shell find $(MAP_FOLDER) -type f -wholename *.ber)
MAPS := $(MAPS:$(MAP_FOLDER)/%=%)
VALGRIND_FOLDER := valgrind_logs
VALGRIND_LOGS := $(MAPS:%.ber=$(VALGRIND_FOLDER)/%.txt)
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes

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

enable_debug:
	rm -rf $(VALGRIND_FOLDER)
	export SO_LONG_DEBUG=1; $(MAKE) -s all

run_valgrind: | enable_debug $(VALGRIND_FOLDER) $(VALGRIND_LOGS)

$(VALGRIND_FOLDER):
	mkdir -p $@

$(VALGRIND_FOLDER)/%.txt : $(MAP_FOLDER)/%.ber
	mkdir -p $(VALGRIND_FOLDER)/$(dir $*)
	valgrind $(VALGRIND_FLAGS) --log-file=$@ ./$(NAME) $< || true

.PHONY: all clean fclean all norminette_errors
