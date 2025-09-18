# =========================
# Name
# =========================
NAME    := philo

# =========================
# Compiler & Flags (42-konform)
# =========================
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g

# =========================
# Quellen & Objekte
# =========================
# Liste alle deine .c-Dateien explizit auf:
SRCS    := main.c utils.c input_check.c routine.c


OBJS    := $(addprefix obj/,$(SRCS:.c=.o))

# =========================
# Default
# =========================
all: $(NAME)

# =========================
# Link
# =========================
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# =========================
# Pattern Rule: .c -> .o
# =========================
obj/%.o: %.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

# =========================
# Objektordner anlegen
# =========================
obj:
	mkdir -p obj

# =========================
# Clean
# =========================
clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

# =========================
# Phony
# =========================
.PHONY: all clean fclean re
.SILENT:
