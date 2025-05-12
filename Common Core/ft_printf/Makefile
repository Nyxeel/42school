NAME := libftprintf.a
HEADER := printf/libftprintf.h

CC := cc
FLAGS := -Wall -Wextra -Werror

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

SRC := \
	printf/1ft_printf.c \
	printf/2ft_va_start.c \
	printf/3find_arg.c \
	printf/4print_str_p_hex.c \
	printf/5print_int.c

OBJ := $(SRC:.c=.o)
RM := rm -f

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(LIBFT)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all
