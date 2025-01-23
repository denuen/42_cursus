NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
CDIR = srcs/
HDIR = includes
CFILES = 	$(wildcard $(CDIR)*.c)
OFILES = $(CFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $@ $^

%.o: %.c $(HDIR)/*
	$(CC) -I $(HDIR) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(CDIR)*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
