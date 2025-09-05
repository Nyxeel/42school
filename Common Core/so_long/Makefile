# =========================
# Names
# =========================
NAME    := so_long

# =========================
# Compiler & Flags (42-konform)
# =========================
CC              := cc
CFLAGS          := -Wall -Wextra -Werror
INCLUDES        := -I. -Ilibft -I./minilibx-linux

# MiniLibX (Linux) – ohne MLX_DIR-Variable
LDFLAGS         := -L ./minilibx-linux
LDLIBS          := -lmlx -lXext -lX11 -lbsd

# =========================
# Libft
# =========================
LIBFT_DIR       := libft
LIBFT_A         := $(LIBFT_DIR)/libft.a

# =========================
# Sources
# =========================
MAIN_SOURCE     := main.c

# Pflicht-Quellen (mandatory)
SOURCES_CORE    := \
	check_map.c \
	check_map2.c \
	utils.c \
	load_game.c \
	mlx_init.c \
	move_counter.c \
	update_game.c

# Bonus-Zusatz (ersetzt update_game.c)
SOURCES_BONUSONLY := \
	update_game_bonus.c

# =========================
# Build-Mode (mandatory / bonus)
# =========================
MODE ?= mandatory

ifeq ($(MODE),bonus)
OBJ_DIR   := objects_bonus/
# Wichtig: update_game.c im Bonus ausschließen, wenn update_game_bonus.c es ersetzt
SOURCES   := $(filter-out update_game.c,$(SOURCES_CORE)) $(SOURCES_BONUSONLY)
else
OBJ_DIR   := objects/
SOURCES   := $(SOURCES_CORE)
endif

# =========================
# Objects
# =========================
HEADERS       := so_long.h libft/libft.h
MAIN_OBJECT   := $(addprefix $(OBJ_DIR),$(MAIN_SOURCE:.c=.o))
OBJECTS       := $(addprefix $(OBJ_DIR),$(SOURCES:.c=.o))

# =========================
# Default Target
# =========================
all: $(NAME)

# =========================
# Link: Programm (kein unnötiges Relinken)
# =========================
$(NAME): $(MAIN_OBJECT) $(OBJECTS) $(LIBFT_A)
	@$(CC) $(CFLAGS) -o $@ $(MAIN_OBJECT) $(OBJECTS) $(LIBFT_A) $(LDFLAGS) $(LDLIBS)

# =========================
# Libft bauen (Ziel explizit!)
# =========================
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR) all

# =========================
# Pattern Rule: .c -> .o
# =========================
$(OBJ_DIR)%.o: %.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# =========================
# Objektordner anlegen
# =========================
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# =========================
# Bonus-Target
# =========================
bonus:
	$(MAKE) MODE=bonus all

# =========================
# Clean Targets
# =========================
clean: clean_libft
	rm -rf objects/ objects_bonus/

clean_libft:
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean fclean_libft
	@rm -f $(NAME)

fclean_libft:
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

# =========================
# Phony
# =========================
.PHONY: all clean fclean re bonus clean_libft fclean_libft

