NAME := libft.a          # legt den namen der zu erstellenden bibliothek fest

HEADER := libft.h        # definiert die header-datei als abhängigkeit für die .o-dateien

CC := cc                 # legt den compiler fest, hier standardmäßig 'cc'

FLAGS := -Wall -Wextra -Werror     # aktiviert alle warnungen und behandelt sie als fehler

SRC :=\                  # listet alle quellcodedateien des projekts auf
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_tolower.c\
	ft_toupper.c\
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
	ft_putnbr_fd.c\

OBJ := $(SRC:.c=.o)      # ersetzt die endung .c in der src-liste durch .o und speichert sie als objektdateien

RM := rm -f              # legt den befehl zum löschen von dateien fest

%.o: %.c $(HEADER)       # definiert eine regel wie eine .c-datei zu einer .o-datei kompiliert wird, abhängig vom header
	$(CC) $(FLAGS) -c $< -o $@   

$(NAME): $(OBJ)          # regel zur erstellung der bibliothek aus allen objektdateien
	ar rcs $(NAME) $(OBJ)

all: $(NAME)             # standardziel, wird ausgeführt wenn 'make' ohne argument aufgerufen wird

clean:                   # löscht alle objektdateien
	$(RM) $(OBJ)

fclean: clean            # löscht zusätzlich zur objektdateien auch die erstellte bibliothek
	$(RM) $(NAME)

re: fclean all           # baut das projekt komplett neu,  führt erst fclean, dann all aus.

.PHONY: all clean fclean re   # kennzeichnet diese ziele als künstliche targets, um fehler durch gleichnamige dateien zu vermeiden
