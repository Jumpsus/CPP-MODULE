NAME = ex05

COMPLIER = c++

FLAG = -std=c++98 -Wall -Wextra

SRCS = 	main.cpp \
		Harl.cpp

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(COMPLIER) $(FLAG) -c $< -o $@

$(NAME) : $(OBJS)
		$(COMPLIER) $(FLAG) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all