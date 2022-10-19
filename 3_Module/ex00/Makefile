NAME = ex00

COMPLIER = c++

FLAG = -std=c++98 -Wall -Wextra -Werror -Wshadow

SRCS = 	main.cpp \
		ClapTrap.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp ClapTrap.hpp
	$(COMPLIER) $(FLAG) -c $< -o $@

$(NAME): $(OBJS) ClapTrap.hpp
	$(COMPLIER) $(FLAG) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all
	
