NAME = Animal
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Animal.cpp Dog.cpp Cat.cpp main.cpp Brain.cpp
OBJS = ${SRCS:.cpp=.o}

all : $(NAME)

$(NAME) : $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re%