# =========================
# Name
# =========================
NAME    		:= pipex

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
	access_and_exec.c \
	pipe_and_fork.c \
	cleanup.c \
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
$(NAME): $(MAIN_OBJECT) $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJECT) $(OBJECTS)


# =========================
# Pattern Rule: .c -> .o
# =========================
$(OBJ_DIR)%.o: %.c  $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# =========================
# Objektordner anlegen
# =========================
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# =========================
# Debugging
# =========================

#debug: CFLAGS += -g
#debug: re

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
	rm -f $(NAME)

re: fclean all

# =========================
# Phony
# =========================
.PHONY: all clean fclean re bonus
#.SILENT:
