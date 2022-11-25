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

CLIENT_FOLDER := $(OBJECTS_FOLDER)/client
CLIENT_SOURCES := client.c
CLIENT_OBJECTS := $(addprefix $(CLIENT_FOLDER)/,$(CLIENT_SOURCES:%.c=%.o))

SERVER_FOLDER := $(OBJECTS_FOLDER)/server
SERVER_SOURCES := server.c
SERVER_OBJECTS := $(addprefix $(SERVER_FOLDER)/,$(SERVER_SOURCES:%.c=%.o))

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_FOLDER)/%.o : %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER): $(SERVER_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER_FOLDER)/%.o : %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: | fclean all

.PHONY: all clean fclean re
