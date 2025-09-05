# Namen
NAME  := push_swap

# Ordner
OBJ_DIR       := objects/

# Compiler & Flags
CC            := cc
CFLAGS        := -Wall -Wextra -Werror

# Header
HEADERS       := push_swap.h
INCLUDES      := -I .

CORE_SOURCES  := commands.c create_list.c find_cheapest.c \
                 push_back.c push_to_b.c sorting_utils.c \
                 start_sorting.c utils.c
MAIN_SOURCE   := main.c

# Objektlisten
CORE_OBJECTS  := $(CORE_SOURCES:%.c=$(OBJ_DIR)%.o)
MAIN_OBJECT   := $(OBJ_DIR)$(MAIN_SOURCE:.c=.o)

# Default: baue das Binary
all: $(NAME)

# Binary direkt aus allen Objekten bauen
$(NAME): $(MAIN_OBJECT) $(CORE_OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $^

# Generische Regel: .c -> .o
$(OBJ_DIR)%.o: %.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


# Objektordner anlegen
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Aufräumen
clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
