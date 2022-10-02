NAME = ex01

FLAG = -std=c++98 -Wall -Wextra -Werror

COMPLIER = c++

SRCS = 	main.cpp \
		zombieHorde.cpp \
		Zombie.cpp \

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp Zombie.hpp
	echo "Compiling $<"
	$(COMPLIER) $(FLAG) -c $< -o $@

$(NAME): $(OBJS) Zombie.hpp
	$(COMPLIER) $(FLAG) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
