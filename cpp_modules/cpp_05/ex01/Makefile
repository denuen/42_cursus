NAME		= Bureaucrat
CXX			= c++
CXX_FLAGS	= -Wall -Wextra -Werror

SRCS		= Bureaucrat.cpp Form.cpp main.cpp
HEADERS		= Bureaucrat.hpp Form.hpp
OBJS		= $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_FLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
