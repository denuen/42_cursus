NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
CDIR = srcs/
HDIR = includes
LIBFT = libft
CFILES = ft_printf.c ft_printf_utils.c ft_printf_proc.c
SRCS = $(addprefix $(CDIR), $(CFILES))
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) 
	make -C libft
	mv libft/libft.a $@
	ar rcs $@ $^

%.o: %.c $(HDIR)/*
	$(CC) -I $(HDIR) $(FLAGS) -c $< -o $@

#bonus: $(OBJS)
#	make bonus -C libft
#	mv libft/libft.a $(NAME)
#	ar rcs $(NAME) $^

clean:
	rm -rf *.o
	rm -rf $(CDIR)*.o
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all
	make re -C libft

.PHONY: all clean fclean re
