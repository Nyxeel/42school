NAME = libunit.a

CC = cc

OBJ_DIR = objects/

CFLAGS = -Wall -Wextra -Werror -Ilibft

HEADERS = libunit.h libft/libft.h

SOURCES = cmp_nums.c

OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)%.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(LIBFT):
	make -C libft

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LIBFT) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft

fclean:
	rm -rf $(OBJ_DIR) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re