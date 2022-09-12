SRCS = ./src/philo.c \
	./src/check.c \
	./src/libft.c \
	./src/print.c \
	./src/time.c	\
	./src/child_real.c \
	./src/thread.c \

OBJS = $(SRCS:.c=.o)

NAME = philo

HEADER = ./include/philo.h

CC = gcc

# gcc -pthread

CFLAGS = -Wall -Wextra -Werror

# -fsanitize=thread

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
	./philo 4 310 200 100 #Un filosofo debería morir 	



#1 800 200 200 #El filosofo no debe comer y debe morir 					OK

#5 800 200 200 #Nadie debería morir 									OK

#5 800 200 200 7 #Solo comen 7 veces 									OK
#5 800 200 200 7 | grep "4 is eating" | wc -l

#4 410 200 200 #Nadie debería morir 									OK

#4 310 200 100 #Un filosofo debería morir 								OK