NAME := libftprintf.a
HEADER := libftprintf.h

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRC := \
	printf/1ft_printf.c \
	printf/2ft_va_start.c \
	printf/3find_arg.c \
	printf/4print_base.c \
	printf/5print_str.c


OBJ := $(SRC:.c=.o)
RM := rm -f

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

