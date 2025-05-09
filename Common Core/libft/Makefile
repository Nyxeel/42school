NAME := libft.a

HEADER := libft.h

CC := cc

FLAGS := -Wall -Wextra -Werror

SRC :=\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_split.c\
	ft_strlen.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_strncmp.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strnstr.c\
	ft_strdup.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_substr.c\
	ft_memset.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_atoi.c\
	ft_itoa.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c

BONUS :=\
	ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstmap_bonus.c\
	ft_lstsize_bonus.c

OBJ := $(SRC:.c=.o)

BONUS_OBJ := $(BONUS:.c=.o)

RM := rm -f

GREEN := \033[0;32m	#ANSI Colorcodes

RED := \033[0;31m

RESET := \033[0m


%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)\n\t✅ MANDATORY SUCCESS\n$(RESET)"

bonus: $(OBJ) $(BONUS_OBJ)
	@ar rcs $(NAME) $(BONUS_OBJ)
	@echo "$(GREEN)\n\t✅ BONUS SUCCESS\n$(RESET)"
	@touch bonus

all: $(NAME)

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ) bonus

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)\n\t🗑️  CLEANED ALL FILES\n$(RESET)"

re: fclean all
	@echo "$(GREEN)\n\t🔄 FULL REBUILD COMPLETE\n$(RESET)"

.PHONY: all clean fclean re
