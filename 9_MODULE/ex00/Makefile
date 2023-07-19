NAME = btc
SOURCES = ./srcs
INCLUDES = ./includes
OBJECTS = ./bin

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
CINCLUDES = -I ${INCLUDES}

SRCS = 	utils.cpp \
		BitcoinExchange.cpp \
		main.cpp \

OBJS = $(addprefix ${OBJECTS}/, $(SRCS:%.cpp=%.o))

BLACK		:=	"\033[1;30m"
RED			:=	"\033[1;31m"
GREEN		:=	"\033[1;32m"
CYAN		:=	"\033[1;35m"
BLUE		:=	"\033[1;36m"
WHITE		:=	"\033[1;37m"
EOC			:=	"\033[0;0m"

${OBJECTS}/%.o : ${SOURCES}/%.cpp
	@ mkdir -p $(dir $@)
	@ echo "Make Binaryfile from " $(BLUE) "$< " $(EOC) "to" $(GREEN) "$@" $(EOC)
	@ ${CC} ${FLAGS} -o $@ -c $< ${CINCLUDES}

${NAME}: ${OBJS}
	@ echo "Create Program " $(WHITE) $@ $(EOC)
	@ ${CC} ${FLAGS} ${CINCLUDES} -o $@ ${OBJS}

all: ${NAME}

clean:
	@ echo "Delete Object file at " $(RED) ${OBJECTS} $(EOC)
	@ rm -rf ${OBJECTS}

fclean: clean
	@ echo "Delete Program " $(RED) ${NAME} $(EOC)
	@ rm -rf ${NAME}

re: fclean all
