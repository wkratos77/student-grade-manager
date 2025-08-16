
NAME = grade_manager
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c io.c student.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
