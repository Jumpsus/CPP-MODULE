NAME = ex02

COMPLIER = c++

FLAG = -std=c++98 -Wall -Wextra -Werror

SRCS = 	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
	$(COMPLIER) $(FLAG) -c $< -o $@

$(NAME): $(OBJS) ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
	$(COMPLIER) $(FLAG) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all
	
