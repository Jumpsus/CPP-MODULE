NAME = ex00

STD = -std=c++98

FLAG = -Wall -Wextra -Werror

COMPLIER = c++

SRCS = 	main.cpp \
		randomChump.cpp\
		Zombie.cpp \
		newZombie.cpp

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
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
