NAME = ex03

COMPLIER = c++

FLAG = -std=c++98 -Wall -Wextra -Werror

SRCS = 	main.cpp			\
		AMateria.cpp		\
	   	Character.cpp		\
		MateriaSource.cpp	\
		Ice.cpp				\
		Cure.cpp			\

OBJS = ${SRCS:.cpp=.o}

%.o : %.cpp AMateria.hpp IMateriaSource.hpp ICharacter.hpp MateriaSource.hpp Character.hpp Cure.hpp Ice.hpp
	$(COMPLIER) $(FLAG) -c $< -o $@

$(NAME) : $(OBJS) AMateria.hpp IMateriaSource.hpp ICharacter.hpp MateriaSource.hpp Character.hpp Cure.hpp Ice.hpp
	$(COMPLIER) $(FLAG) $(OBJS) -o $(NAME) 

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all