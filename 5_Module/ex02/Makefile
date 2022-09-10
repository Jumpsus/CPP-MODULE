NAME = ex02

COMPLIER = c++

FLAG = -std=c++98 -Wall -Wextra -Werror

SRCS = 	Bureaucrat.cpp 				\
		ShrubberyCreationForm.cpp	\
		RobotomyRequestForm.cpp		\
		PresidentialPardonForm.cpp	\
		Form.cpp	   				\
		main.cpp

OBJS = ${SRCS:.cpp=.o}

%.o :	%.cpp Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp	PresidentialPardonForm.hpp
		$(COMPLIER) $(FLAG) -c $< -o $@

$(NAME) : 	$(OBJS)
			$(COMPLIER) $(FLAG) $(OBJS) -o $(NAME)

all : $(NAME)

clean : 
			rm -rf $(OBJS)

fclean : 	clean
			rm -rf $(NAME)

re : fclean all



