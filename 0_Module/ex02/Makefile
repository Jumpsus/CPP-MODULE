NAME = account

SRCS = Account.cpp tests.cpp \

OBJS = $(SRCS:.cpp=.o)

CPP = c++

FLAG = -std=c++98 -Wall -Wextra -Werror

all : $(NAME)

%.o : %.cpp
	$(CPP) $(FLAG) -c $<

$(NAME) : $(OBJS) Account.hpp
	$(CPP) $(FLAG) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
