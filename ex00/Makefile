SRCS		= *.c

OBJS		= ${SRCS:.c=.o}

NAME		= rush-02

CC			= gcc

CCFLAGS 	= -Wall -Werror -Wextra

all:		${NAME}

${NAME}: 			
					${CC} -c ${CCFLAGS} ${SRCS}
					${CC} ${CCFLAGS} -o ${NAME} ${OBJS}
clean:
					rm -f ${OBJS}

fclean:		clean
					rm -f ${NAME}

re:			fclean all
		
.PHONY:		all clean fclean re
