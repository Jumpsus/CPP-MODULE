NAME = megaphone

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

CPP = g++

FLAG = -std=c++98 -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(FLAG) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
