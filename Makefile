SRCS = philo.c \
	check.c \
	libft.c \
	print.c \
	child.c \
	time.c	\

OBJS = $(SRCS:.c=.o)

NAME = philo

HEADER = philo.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=thread

# -Wall -Wextra -Werror  -fsanitize=thread

RM = rm -f

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(SRC) -I $(HEADER) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norme:
	norminette -R CheckForbiddenSourceHeader $(SRCS)

test: all
	./philo 4 200 200 200