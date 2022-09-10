NAME = ex02

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

COMPLIER = c++

FLAG = -std=c++98 -Wall -Wextra -Werror

%.o : %.cpp
	$(COMPLIER) $(FLAG) -c $< -o $@

$(NAME) : $(OBJ)
	$(COMPLIER) $(FLAG) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all