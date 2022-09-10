NAME = ex03

SRCS = 	main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp \

OBJS = $(SRCS:.cpp=.o)

COMPLIER = c++

FLAG = -std=c++98 -Wall -Wextra -Werror

%.o : %.cpp HumanA.hpp HumanB.hpp Weapon.hpp
	$(COMPLIER) $(FLAG) -c $< -o $@

$(NAME) : $(OBJS)
	$(COMPLIER) $(FLAG) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all