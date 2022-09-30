NAME = ex01

COMPLIER = c++

FLAG = -std=c++98 -Wall -Wextra -Werror

SRCS = 	main.cpp	\
		Span.cpp

OBJS = ${SRCS:.cpp=.o}

%.o : 	%.cpp Span.hpp
		$(COMPLIER) $(FLAG) -c $< -o $@

$(NAME): $(OBJS) Span.hpp
		$(COMPLIER) $(FLAG) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
			rm -rf $(OBJS)

fclean :	clean
			rm -rf $(NAME)

re : fclean all