NAME = ex04

COMPLIER = c++

FLAG = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

%.o : %.cpp
	$(COMPLIER) $(FLAG) -c $< -o $@

$(NAME) : $(OBJ)
	$(COMPLIER) $(FLAG) $(OBJ) -o $(NAME)

all : $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

clear_test:
	@rm -rf test
	@rm -rf test.replace

test: all clear_test
	@echo "=== Create test ==="
	@echo "a b c d e f g h " >> test
	@echo "i j k l m n o p " >> test
	@echo "q r s t u v w x " >> test
	@echo "y z " >> test
	@echo "1 2 3 4 5 6 7 8 " >> test
	@cat test

	@echo "=== Result ==="
	./$(NAME) test " " "[SED REPLACE]"
	@echo ""
	@cat test.replace