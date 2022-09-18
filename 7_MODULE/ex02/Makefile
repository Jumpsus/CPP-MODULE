NAME = ex02

COMPLIER = c++

FLAG = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp

OBJS = ${SRCS:.cpp=.o}

%.o : 	%.cpp Array.hpp
		$(COMPLIER) $(FLAG) -c $< -o $@

$(NAME): $(OBJS) Array.hpp
		$(COMPLIER) $(FLAG) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
			rm -rf $(OBJS)

fclean :	clean
			rm -rf $(NAME)

re : fclean all