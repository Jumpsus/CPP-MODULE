NAME = convert

COMPLIER = c++

FLAG = -std=c++98 -Wall -Wextra -Werror

SRCS = 	utils.cpp \
		main.cpp

OBJS = ${SRCS:.cpp=.o}

%.o :	%.cpp utils.hpp
		$(COMPLIER) $(FLAG) -c $< -o $@

$(NAME) : 	$(OBJS)
			$(COMPLIER) $(FLAG) $(OBJS) -o $(NAME)

all : $(NAME)

clean : 
			rm -rf $(OBJS)

fclean : 	clean
			rm -rf $(NAME)

re : fclean all



