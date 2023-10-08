NAME = ft_display_file
SRCSDIR = srcs
OBJSDIR = objs

FILES = main.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_display_file.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(FILES:%.c=$(SRCSDIR)/%.c)
OBJS = $(FILES:%.c=$(OBJSDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@echo "Compiling $@"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
