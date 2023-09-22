NAME=libstack.a
SRC= stack.c
OBJ= $(SRC:.c=.o)
CC= gcc
CFLAGS= -Wall -Wextra -Werror 


all: $(NAME)


$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re



