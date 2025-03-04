NAME = program
CC = gcc
FLAGS = -Wall -Wextra -Werror
CFILES = main.c get_next_line.c get_next_line_utils.c
OFILES = $(CFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) -o $@ $^
	rm -rf $^

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
