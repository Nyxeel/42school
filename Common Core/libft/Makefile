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
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstlast.c\
	ft_lstmap.c\
	ft_lstsize.c

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
	@echo "$(GREEN)✅ MANDATORY SUCCESS$(RESET)"

bonus: $(OBJ) $(BONUS_OBJ)
	@ar rcs $(NAME) $(BONUS_OBJ)
	@echo "$(GREEN)✅ BONUS SUCCESS$(RESET)"


all: $(NAME)
	@echo "$(GREEN)✅ BUILD SUCCESS$(RESET)"


clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)\t🗑️  CLEANED ALL FILES$(RESET)"

re: fclean all
	@echo "$(GREEN)🔄 FULL REBUILD COMPLETE$(RESET)"

.PHONY: all clean fclean re bonus
