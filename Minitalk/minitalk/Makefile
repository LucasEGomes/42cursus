# ifneq (VERBOSE, 0)
# MAKEFLAGS += -s
# endif

CLIENT := client
SERVER := server

CC := gcc
CFLAGS := -Wall -Wextra -Werror -MMD -I $(abspath .)
ifdef MINITALK_DEBUG
CFLAGS += -g3
else
CFLAGS += -O2
endif

OBJECTS_FOLDER := objs

CLIENT_SOURCES := client.c \
	utils/ft_atoi.c \
	utils/ft_count_digits.c \
	utils/ft_strlen.c \
	utils/ft_write.c
CLIENT_OBJECTS := $(addprefix $(OBJECTS_FOLDER)/,$(CLIENT_SOURCES:%.c=%.o))

SERVER_SOURCES := \
	server.c \
	utils/ft_itoa.c \
	utils/ft_strlen.c \
	utils/ft_write.c
SERVER_OBJECTS := $(addprefix $(OBJECTS_FOLDER)/,$(SERVER_SOURCES:%.c=%.o))

BONUS_FOLDER := bonus

BONUS_CLIENT := $(BONUS_FOLDER)/client_bonus
BONUS_CLIENT_SOURCES := \
	$(BONUS_FOLDER)/client_bonus.c \
	minitalk_errors.c \
	utils/ft_atoi.c \
	utils/ft_absolute.c \
	utils/ft_count_digits.c \
	utils/ft_print.c \
	utils/ft_strlen.c \
	utils/ft_write.c
BONUS_CLIENT_OBJECTS := $(addprefix $(OBJECTS_FOLDER)/,$(BONUS_CLIENT_SOURCES:%.c=%.o))

BONUS_SERVER := $(BONUS_FOLDER)/server_bonus
BONUS_SERVER_SOURCES := \
	$(BONUS_FOLDER)/server_bonus.c \
	minitalk_errors.c \
	utils/ft_absolute.c \
	utils/ft_count_digits.c \
	utils/ft_itoa.c \
	utils/ft_print.c \
	utils/ft_strlen.c \
	utils/ft_write.c
BONUS_SERVER_OBJECTS := $(addprefix $(OBJECTS_FOLDER)/,$(BONUS_SERVER_SOURCES:%.c=%.o))

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER): $(SERVER_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(BONUS_CLIENT) $(BONUS_SERVER)

$(BONUS_CLIENT): $(BONUS_CLIENT_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(BONUS_SERVER): $(BONUS_SERVER_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJECTS_FOLDER)/%.o : %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: | fclean all

.PHONY: all clean fclean re bonus
