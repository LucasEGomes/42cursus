.DEFAULT_GOAL := all
ifndef VERBOSE
MAKEFLAGS += -s
endif

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
	game_state.c \
	gui.c \
	main.c \
	map.c \
	map_validators.c \
	player_move.c \
	player_move_utils.c \
	print_utils.c \
	render.c \
	render_utils.c \
	render_animations.c \
	string_utils.c \
	validators.c
OBJECTS_FOLDER := objects
OBJECTS := $(SOURCES:%.c=$(OBJECTS_FOLDER)/%.o)

DEPENDENCIES := $(OBJECTS:%.o=%.d)
-include $(DEPENDENCIES)

MAP_FOLDER := maps
MAPS := $(shell find $(MAP_FOLDER) -type f -wholename *.ber)
MAPS := $(MAPS:$(MAP_FOLDER)/%=%)

VALGRIND_FOLDER := valgrind_logs
VALGRIND_LOGS := $(MAPS:%.ber=$(VALGRIND_FOLDER)/%.txt)
VALGRIND_LOGS += $(addprefix $(VALGRIND_FOLDER)/invalid/,file_do_not_exists.txt file_without_permissions.txt)
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes
NORMINETTE := norminette_errors

all: $(OBJECTS_FOLDER) $(MLX_NAME) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LIBRARIES) -o $@

$(OBJECTS_FOLDER):
	mkdir -p $@

$(OBJECTS_FOLDER)/%.o: %.c
	$(CC) -MMD $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(MLX) clean
	rm -rf $(OBJECTS_FOLDER)
	rm -f $(MLX_NAME)

fclean: clean
	rm -rf $(NAME) $(NORMINETTE) $(VALGRIND_FOLDER)

re: | fclean all

$(MLX_NAME): $(MLX)
	$(MAKE) -C $< all
	cp $</$@ .

$(MLX):
	git clone https://github.com/42Paris/minilibx-linux $@

$(NORMINETTE):
	norminette *.c *.h | grep -v OK! > $@ || true
	cat $@

clean_valgrind_logs:
	rm -rf $(VALGRIND_FOLDER)

enable_debug:
	export SO_LONG_DEBUG=1; $(MAKE) -s all

run_valgrind: | clean_valgrind_logs enable_debug $(VALGRIND_FOLDER) $(VALGRIND_LOGS)


$(VALGRIND_FOLDER):
	mkdir -p $@

$(VALGRIND_FOLDER)/%.txt : $(MAP_FOLDER)/%.ber
	mkdir -p $(VALGRIND_FOLDER)/$(dir $*)
	valgrind $(VALGRIND_FLAGS) --log-file=$@ ./$(NAME) $< || true

$(VALGRIND_FOLDER)/invalid/file_do_not_exists.txt:
	valgrind $(VALGRIND_FLAGS) --log-file=$@ ./$(NAME) $(MAP_FOLDER)/file_do_not_exists.ber || true

$(VALGRIND_FOLDER)/invalid/file_without_permissions.txt:
	touch $(MAP_FOLDER)/file_without_permissions.ber
	chmod 0000 $(MAP_FOLDER)/file_without_permissions.ber
	valgrind $(VALGRIND_FLAGS) --log-file=$@ ./$(NAME) $(MAP_FOLDER)/file_without_permissions.ber || true
	rm -f $(MAP_FOLDER)/file_without_permissions.ber

.PHONY: all clean fclean all norminette_errors
