# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 13:27:44 by oumondad          #+#    #+#              #
#    Updated: 2024/08/03 16:16:51 by oumondad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minishell

SRC = minishell.c tools.c linked_list.c env_parse.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = cc

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean :
	rm -rf ${OBJ} ${BOBJ}

fclean : clean
	rm -rf ${NAME} ${BNAME}

re : fclean all

.PHONY : re all clean fclean

.SECONDARY: $(OBJ)