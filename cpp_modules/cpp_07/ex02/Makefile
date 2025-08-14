NAME		= Array
CXX			= c++
CXX_FLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp
HEADERS		= $(wildcard *.hpp)
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_FLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
