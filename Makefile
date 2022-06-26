NAME		= 	philo

MAKEFILE	= 	Makefile

SRC			= 	check.c error_exit.c main.c make_threads.c philo_init.c utils.c
				
OBJS		= ${SRC:.c=.o}

D_FILES		= $(patsubst %.c, %.d, $(SRC))

HEADER		= philo.h

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

.PHONY		:	all clean fclean re

all			:	${NAME}

%.o 		: %.c ${MAKEFILE}
			$(CC) -c $< -o $@ -MD

$(NAME)	:	${OBJS}
			$(CC) $(OBJS) -o $(NAME)
			
clean		:
	@rm -f ${OBJS} ${D_FILES}

fclean	:	clean
	@${RM} ${NAME}

-include $(D_FILES)

re		:	fclean all