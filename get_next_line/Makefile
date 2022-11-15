# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 10:56:46 by balnahdi          #+#    #+#              #
#    Updated: 2022/04/06 10:56:48 by balnahdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

SRC =	get_next_line_utils.c get_next_line.c

OBJS = ${SRC:.c=.o}

CC		= gcc
RM		= rm -f
 
CFLAGS = -c -Wall -Wextra -Werror
 
.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}
 
$(NAME): ${OBJS}
		ar -rcs ${NAME} ${OBJS}

all:	${NAME}
 
clean:
		${RM} ${OBJS}
 
fclean:	clean
		${RM} ${NAME}
 
re:	fclean all