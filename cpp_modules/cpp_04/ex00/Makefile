NAME		= Animals

CXX			= c++
CXX_FLAGS	= -Wall -Wextra -Werror -std=c++98

CXX_FILES	= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp WrongDog.cpp
OBJS		= $(CXX_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_FLAGS) $^ -o $@

%.o:%.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
