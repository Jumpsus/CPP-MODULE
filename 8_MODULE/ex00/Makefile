NAME = ex00

COMPLIER = c++

FLAG = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp

OBJS = ${SRCS:.cpp=.o}

%.o : 	%.cpp easyfind.hpp
		$(COMPLIER) $(FLAG) -c $< -o $@

$(NAME): $(OBJS) easyfind.hpp
		$(COMPLIER) $(FLAG) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
			rm -rf $(OBJS)

fclean :	clean
			rm -rf $(NAME)

re : fclean all