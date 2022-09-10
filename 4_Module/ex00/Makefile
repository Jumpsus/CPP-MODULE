NAME = ex00

COMPLIER = c++

FLAG = -std=c++98 -Wall -Wextra -Werror

SRCS = 	main.cpp \
		Cat.cpp \
		Dog.cpp \
		Animal.cpp \

OBJS = ${SRCS:.cpp=.o}

%.o : 	%.cpp Cat.hpp Dog.hpp Animal.hpp
		$(COMPLIER) $(FLAG) -c $< -o $@

$(NAME) :	$(OBJS) Cat.hpp Dog.hpp Animal.hpp
			$(COMPLIER) $(FLAG) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all

