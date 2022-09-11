NAME = ex02

COMPLIER = c++

FLAG = -std=c++98 -Wall -Wextra -Werror

SRCS = 	utils.cpp	\
		Base.cpp	\
		A.cpp		\
		B.cpp		\
		C.cpp		\
		main.cpp

OBJS = ${SRCS:.cpp=.o}

%.o :	%.cpp Base.hpp A.hpp B.hpp C.hpp utils.hpp
		$(COMPLIER) $(FLAG) -c $< -o $@

$(NAME) : 	$(OBJS)
			$(COMPLIER) $(FLAG) $(OBJS) -o $(NAME)

all : $(NAME)

clean : 
			rm -rf $(OBJS)

fclean : 	clean
			rm -rf $(NAME)

re : fclean all



