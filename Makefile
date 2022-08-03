# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 10:09:52 by ychibani          #+#    #+#              #
#    Updated: 2022/08/03 17:45:37 by ychibani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES			=	srcs/philosophers/philosophers.c	\
						srcs/philosophers/routine.c			\
						srcs/parsing/parsing.c				\
						srcs/init/init_data.c				\
						srcs/clean/clean.c					\
						srcs/utils/death.c					\

HEADER_FILES		=	philosophers_structs.h 			\
						philosophers_fonctions.h		\
						philosophers_defines.h			\

NAME				=	philo

OBJS_FILES 			= 	${SRCS_FILES:.c=.o}

DEPS_FILES			=	${SRCS_FILES:.c=.d}

INCS				=	-I ./includes

CC					=	clang

CFLAGS				=  	-Wall -Werror -Wextra -DLinux 

RM					=	rm -rf


_END=$'\e[0m
_BOLD=$'\e[1m
_UNDER=$'\e[4m
_REV=$'\e[7m
_GREY=$'\e[30m
_RED=$'\e[0;31m
_GREEN=$'\e[32m
_YELLOW=$'\e[33m
_BLUE=$'\e[34m
_PURPLE=$'\e[35m
_CYAN=$'\e[36m
_WHITE=$'\e[37m

_IGREY=$'\e[40m
_IRED=$'\e[41m
_IGREEN=$'\e[42m
_IYELLOW=$'\e[43m
_IBLUE=$'\e[44m
_IPURPLE=$'\e[45m
_ICYAN=$'\e[46m
_IWHITE=$'\e[47m


all:			${NAME}

.c.o:
				@echo "Compiling ${_YELLOW}${_BOLD}$<${_END}..."
				@${CC} ${CFLAGS} -g ${INCS} -MMD -c $< -o $@ ${INCS}

${NAME}:		${OBJS_FILES}
				@echo "${_CYAN}${_BOLD}Philosophers files compiled !${_END}..."
				@${CC} ${CFLAGS} -lpthread ${INCS} ${OBJS_FILES} -o ${NAME}

clean:
				@echo "Deleting ${_RED}${_BOLD}binary files${_END}..."
				@${RM} ${OBJS_FILES} ${DEPS_FILES}

fclean:			clean
				@echo "Deleting ${_RED}${_BOLD}executable${_END}..."
				@${RM} ${NAME}

re:				fclean all

git:		
			git add .
			git commit -m "$m"
			git push -f origin master

-include ${DEPS_FILES}

.PHONY:			all clean fclean re
