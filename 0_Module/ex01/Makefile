NAME = phonebook

SRCS = PhoneBook.cpp Contact.cpp main.cpp \

OBJS = $(SRCS:.cpp=.o)

CPP = c++

FLAG = -std=c++98 -Wall -Wextra -Werror

all : $(NAME)

%.o : %.cpp
	$(CPP) $(FLAG) -c $<

$(NAME) : $(OBJS) Contact.hpp PhoneBook.hpp
	$(CPP) $(FLAG) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
