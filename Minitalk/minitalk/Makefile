# ifneq (VERBOSE, 0)
# MAKEFLAGS += -s
# endif

CLIENT := client
SERVER := server

CC := gcc
CFLAGS := -Wall -Wextra -Werror -MMD
ifdef (MINITALK_DEBUG)
CFLAGS += -g3
else
CFLAGS += -O2
endif

OBJECTS_FOLDER := objs

CLIENT_SOURCES := client.c \
	ft_atoi.c \
	ft_strlen.c \
	ft_write.c
CLIENT_OBJECTS := $(addprefix $(OBJECTS_FOLDER)/,$(CLIENT_SOURCES:%.c=%.o))

SERVER_SOURCES := \
	server.c \
	ft_itoa.c \
	ft_strlen.c \
	ft_write.c
SERVER_OBJECTS := $(addprefix $(OBJECTS_FOLDER)/,$(SERVER_SOURCES:%.c=%.o))

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER): $(SERVER_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJECTS_FOLDER)/%.o : %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: | fclean all

.PHONY: all clean fclean re
