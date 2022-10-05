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

HEADER = ./include/philo.h

CC = gcc

# gcc -pthread

CFLAGS = -Wall -Wextra -Werror -MMD

# -fsanitize=thread

# -Wall -Wextra -Werror  -fsanitize=thread

RM = rm -f

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(SRC) -I $(HEADER) -c $< -o $(<:.c=.o)

-include $(DEPS)
$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
#DUDA DE SI SE COMPILA SRC O OBJS

clean:
	$(RM) $(OBJS) $(DEPS_DEL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norme:
	norminette -R CheckForbiddenSourceHeader $(SRCS)

test: re
	./philo 4 410 200 200



#1 800 200 200 #El filosofo no debe comer y debe morir 					OK

#5 800 200 200 #Nadie debería morir 									OK

#5 800 200 200 7 #Solo comen 7 veces 									OK
#5 800 200 200 7 | grep "4 is eating" | wc -l							OK

#4 410 200 200 #Nadie debería morir 									OK

#4 310 200 100 #Un filosofo debería morir 								OK



# Test Lazy
#100 800 200 200 #Nadie deberia morir
#105 800 200 200 #Nadie deberia morir
#200 800 200 200 #Nadie deberia morir

