NAME		= philo
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
SRCS_DIR	= srcs/
H_DIR		= includes
CFILES		= main.c general_utils.c philo.c philo_mm.c philo_init.c philo_operations.c philo_utils.c
SRCS		= $(addprefix $(SRCS_DIR), $(CFILES))
OBJS		= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "make: Executable created"

$(OBJS): %.o: %.c
	@$(CC) $(FLAGS) -I $(H_DIR) -c $< -o $@
	@$(eval print_objs_msg = @:)
	$(print_objs_msg)

clean:
	@rm -f $(SRCS_DIR)*.o
	@if [ -n "$(wildcard $(SRCS_DIR)*.o)" ]; then \
		rm -f $(SRCS_DIR)*.o; \
		echo "make: Object files deleted"; \
	else \
		echo "make: Nothing to be done for 'clean'"; \
	fi

fclean: clean
	@if [ -e $(NAME) ]; then \
		rm -f $(NAME); \
		echo "make: Executable deleted"; \
	else \
		echo "make: Nothing to be done for 'fclean'"; \
	fi

re: fclean all

.PHONY: all clean fclean re print_objs_msg
