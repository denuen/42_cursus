SERVER_NAME	= server
CLIENT_NAME	= client
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
HDIR_LIBFT	= libft/includes
LIBFT		= libft/libft.a

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): server.o $(LIBFT)
	$(CC) $(FLAGS) $< $(LIBFT) -o $@

$(CLIENT_NAME): client.o $(LIBFT)
	$(CC) $(FLAGS) $< $(LIBFT) -o $@

$(LIBFT):
	@$(MAKE) -C libft

%.o: %.c
	@$(CC) $(FLAGS) -I $(HDIR_LIBFT) -c $< -o $@

clean:
	@rm -f client.o server.o
	@$(MAKE) -C libft clean

fclean: clean
	@rm -f client server
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
