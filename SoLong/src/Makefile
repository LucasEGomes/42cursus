NAME := so_long

all: $(NAME)

$(NAME): libmlx.a

libmlx.a: minilibx-linux
	$(MAKE) -C $<

minilibx-linux:
	git clone https://github.com/42Paris/minilibx-linux $@
