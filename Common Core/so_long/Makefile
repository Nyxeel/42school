# Namen
LIB_NAME      := solong.a
PROGRAM_NAME  := so_long

# Ordner
OBJ_DIR       := objects/

# Compiler & Flags (42‑konform)
CC            := cc
CFLAGS        := -Wall -Wextra -Werror

# Header
HEADERS       := so_long.h
INCLUDES      := -I .


CORE_SOURCES  := commands.c create_list.c find_cheapest.c \
                 push_back.c push_to_b.c sorting_utils.c \
                 start_sorting.c utils.c
MAIN_SOURCE   := main.c

# Objektlisten
CORE_OBJECTS  := $(CORE_SOURCES:%.c=$(OBJ_DIR)%.o)
MAIN_OBJECT   := $(OBJ_DIR)$(MAIN_SOURCE:.c=.o)

# Default: baue das Binary (und dabei implizit die LIB)
all: $(PROGRAM_NAME)

# LIB bauen: nur aus CORE_OBJECTS
$(LIB_NAME): $(CORE_OBJECTS)
	@ar rcs $(LIB_NAME) $(CORE_OBJECTS)

$(PROGRAM_NAME): $(MAIN_OBJECT) $(LIB_NAME)
	@$(CC) $(CFLAGS) -o $(PROGRAM_NAME) $(MAIN_OBJECT) $(LIB_NAME)

# Generische Regel: .c -> .o (für alle .c in CORE + MAIN)
$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Objektordner anlegen
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Aufräumen
clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(LIB_NAME) $(PROGRAM_NAME)

re: fclean all

.PHONY: all clean fclean re
