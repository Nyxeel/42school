# =========================
# Name
# =========================
NAME    		:= pipex

# =========================
# Compiler & Flags (42-konform)
# =========================
CC              := cc
CFLAGS          := -Wall -Wextra -Werror -MMD -MP -g

# =========================
# Sources
# =========================
# Main-Sources getrennt definieren
MAIN_SOURCE_MAND  := main.c
MAIN_SOURCE_BONUS := main_bonus.c

# Pflicht-Quellen (mandatory)
SOURCES_CORE    := \
	access_and_exec.c \
	pipe_and_fork.c \
	cleanup.c \
	utils.c \
	utils2.c \

# Bonus-Zusatz
SOURCES_BONUSONLY := \
	pipe_and_fork_bonus.c \

# =========================
# Feste Objektpfade
# =========================
OBJ_DIR_MAND        := objects/
OBJ_DIR_BONUS       := objects_bonus/

# Aus den getrennten Main-Sources die jeweiligen Objektpfade bauen
MAIN_OBJECT_MAND    := $(addprefix $(OBJ_DIR_MAND),$(MAIN_SOURCE_MAND:.c=.o))
MAIN_OBJECT_BONUS   := $(addprefix $(OBJ_DIR_BONUS),$(MAIN_SOURCE_BONUS:.c=.o))

OBJECTS_MAND_ALL    := $(addprefix $(OBJ_DIR_MAND),$(SOURCES_CORE:.c=.o))
OBJECTS_MAND_NOFORK := $(filter-out $(OBJ_DIR_MAND)pipe_and_fork.o,$(OBJECTS_MAND_ALL))
OBJECT_BONUS_ONLY   := $(addprefix $(OBJ_DIR_BONUS),$(SOURCES_BONUSONLY:.c=.o))

HEADERS             := pipex.h

# =========================
# Build-Mode (mandatory / bonus)
# =========================
MODE ?= mandatory

ifeq ($(MODE),bonus)
# Bonus-Modus: main_bonus.c in objects_bonus/ + Mandatory (ohne pipe_and_fork.o) + Bonus-Objekt(e)
MAIN_OBJECT := $(MAIN_OBJECT_BONUS)
OBJECTS     := $(OBJECTS_MAND_NOFORK) $(OBJECT_BONUS_ONLY)
else
# Mandatory-Modus: main.c in objects/ + alle Mandatory-Objekte
MAIN_OBJECT := $(MAIN_OBJECT_MAND)
OBJECTS     := $(OBJECTS_MAND_ALL)
endif

DEPS := $(MAIN_OBJECT:.o=.d) $(OBJECTS:.o=.d)

# =========================
# Default Target
# =========================
all: $(NAME)

# =========================
# Link: Programm (kein unnötiges Relinken)
# =========================
$(NAME): $(MAIN_OBJECT) $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# =========================
# Compile-Rules
# =========================
# Mandatory-Objects in objects/
$(OBJ_DIR_MAND)%.o: %.c $(HEADERS) | $(OBJ_DIR_MAND)
	$(CC) $(CFLAGS) -c $< -o $@

# Bonus-Object(s) in objects_bonus/
$(OBJ_DIR_BONUS)%.o: %.c $(HEADERS) | $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

# =========================
# Objektordner anlegen
# =========================
$(OBJ_DIR_MAND):
	mkdir -p $(OBJ_DIR_MAND)

$(OBJ_DIR_BONUS):
	mkdir -p $(OBJ_DIR_BONUS)

# =========================
# Bonus-Target (delegiert an Make, damit Up-to-date geprüft wird)
# =========================
bonus:
	$(MAKE) MODE=bonus all

# =========================
# Clean Targets
# =========================
clean:
	rm -rf $(OBJ_DIR_MAND) $(OBJ_DIR_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Automatisch generierte Dep-Dateien einbinden
-include $(DEPS)

# =========================
# Phony
# =========================
.PHONY: all clean fclean re bonus
# .SILENT:
