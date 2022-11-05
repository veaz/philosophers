SRCS = ./src/philo.c \
	./src/check.c \
	./src/libft.c \
	./src/print.c \
	./src/time.c	\
	./src/child_real.c \
	./src/thread.c \
	./src/utils.c \

OBJS = $(SRCS:.c=.o)

DEPS = $(addsuffix .d, $(basename $(notdir $(SRCS))))

DEPS_DEL = ./*.d ./src/*.d

NAME = philo

HEADER = ./inc/philo.h

CC = gcc


CFLAGS = -Wall -Wextra -Werror -MMD

RM = rm -f

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(SRC) -I $(HEADER) -c $< -o $(<:.c=.o)


-include $(DEPS)
$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS_DEL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norme:
	norminette -R CheckForbiddenSourceHeader $(SRCS) $(HEADER)
