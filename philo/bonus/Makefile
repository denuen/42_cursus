NAME		= philo_bonus
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
SRCS_DIR	= srcs/
H_DIR		= includes
CFILES		= general_utils_bonus.c main_bonus.c philo_bonus.c philo_init_bonus.c philo_mm_bonus.c philo_operations_bonus.c philo_utils_bonus.c
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
