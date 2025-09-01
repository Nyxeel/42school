# =========================
# Names
# =========================
NAME    		:= pipex
LIB_NAME        := pipex.a

# =========================
# Compiler & Flags (42-konform)
# =========================
CC              := cc
CFLAGS          := -Wall -Wextra -Werror

# =========================
# Sources
# =========================
MAIN_SOURCE     := main.c

# Pflicht-Quellen (mandatory)
SOURCES_CORE    := \
	find_access.c \
	pipe_and_fork.c \
	utils.c \
	utils2.c \

# Bonus-Zusatz (ersetzt update_game.c)
SOURCES_BONUSONLY := \
		pipe_and_fork_bonus.c \

# =========================
# Build-Mode (mandatory / bonus)
# =========================
MODE ?= mandatory

ifeq ($(MODE),bonus)
OBJ_DIR   := objects_bonus/
# Wichtig: update_game.c im Bonus ausschließen, wenn update_game_bonus.c es ersetzt
SOURCES   := $(filter-out pipe_and_fork_bonus.c,$(SOURCES_CORE)) $(SOURCES_BONUSONLY)
else
OBJ_DIR   := objects/
SOURCES   := $(SOURCES_CORE)
endif

# =========================
# Objects
# =========================
HEADERS       := pipex.h
MAIN_OBJECT   := $(addprefix $(OBJ_DIR),$(MAIN_SOURCE:.c=.o))
OBJECTS       := $(addprefix $(OBJ_DIR),$(SOURCES:.c=.o))

# =========================
# Default Target
# =========================
all: $(NAME)

# =========================
# Link: Programm (kein unnötiges Relinken)
# =========================
$(NAME): $(MAIN_OBJECT) $(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJECT) $(LIB_NAME)

# =========================
# Archive: Statische Bibliothek (nur bei neuen OBJs)
# =========================
$(LIB_NAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)

# =========================
# Pattern Rule: .c -> .o
# =========================
$(OBJ_DIR)%.o: %.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# =========================
# Objektordner anlegen
# =========================
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# =========================
# Debugging
# =========================

debug: CFLAGS += -g
debug: clean $(NAME)

## valgrind --track-fds=yes --trace-children=yes ./pipex infile "grep 4" "wc -l" outfile

# =========================
# Bonus-Target
# =========================
bonus:
	$(MAKE) MODE=bonus all

# =========================
# Clean Targets
# =========================
clean:
	rm -rf objects/ objects_bonus/

fclean: clean
	rm -f $(LIB_NAME) $(NAME)

re: fclean all

# =========================
# Phony
# =========================
.PHONY: all clean fclean re bonus debug
.SILENT:
