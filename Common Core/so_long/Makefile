# Namen
LIB_NAME        := solong.a
PROGRAM_NAME    := so_long

# Ordner
OBJ_DIR         := objects/

# Compiler & Flags (42‑konform)
CC              := cc
CFLAGS          := -Wall -Wextra -Werror

# Libft (liegt im Projekt-Root)
LIBFT_DIR       := libft
LIBFT_A         := $(LIBFT_DIR)/libft.a

# Header
HEADERS         := so_long.h libft/libft.h
INCLUDES        := -I . -I $(LIBFT_DIR)

# Quellen
CORE_SOURCES    := check_map.c check_map2.c utils.c \
                   load_game.c mlx_init.c update_game.c
MAIN_SOURCE     := main.c

# Bonus (optional; wird nur verwendet, wenn Dateien existieren)
BONUS_SOURCES   := $(wildcard *_bonus.c)

# Objekte
CORE_OBJECTS    := $(CORE_SOURCES:%.c=$(OBJ_DIR)%.o)
MAIN_OBJECT     := $(OBJ_DIR)$(MAIN_SOURCE:.c=.o)
BONUS_OBJECTS   := $(BONUS_SOURCES:%.c=$(OBJ_DIR)%.o)

# Default: baue das Binary (und dabei implizit libft & LIB)
NAME: all
all: $(PROGRAM_NAME)

# Programm bauen (linkt: main + statische CORE-LIB + libft.a)
$(PROGRAM_NAME): $(MAIN_OBJECT) $(LIB_NAME) $(LIBFT_A)
	@$(CC) $(CFLAGS) -o $(PROGRAM_NAME) $(MAIN_OBJECT) $(LIB_NAME) $(LIBFT_A)

# Statische Bibliothek aus den CORE-Objekten
$(LIB_NAME): $(CORE_OBJECTS)
	@ar rcs $(LIB_NAME) $(CORE_OBJECTS)

# libft bauen (über eigenes Makefile)
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

# Generische Regel: .c -> .o (für alle .c in CORE + MAIN + BONUS)
$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Objektordner anlegen
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Aufräumen
clean: clean_libft
	@rm -rf $(OBJ_DIR)

clean_libft:
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean fclean_libft
	@rm -f $(LIB_NAME) $(PROGRAM_NAME)

fclean_libft:
	@$(MAKE) -C $(LIBFT_DIR) fclean || true

re: fclean all

.PHONY: NAME all clean fclean re bonus clean_libft fclean_libft
