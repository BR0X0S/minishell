# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 13:27:44 by oumondad          #+#    #+#              #
#    Updated: 2024/07/18 21:49:58 by oumondad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minishell

SRC = normal_split.c mini_libft.c start.c main.c tansemih_utils.c

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

re : fclean all bonus

.PHONY : re all clean fclean

.SECONDARY: $(OBJ) $(BOBJ)