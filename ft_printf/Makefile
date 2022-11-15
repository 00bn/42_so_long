# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 13:09:26 by balnahdi          #+#    #+#              #
#    Updated: 2021/11/28 14:08:44 by balnahdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = libftprintf.a

SRC =	ft_printf.c	ft_printf_ptr_utils.c	ft_printf_len_utils.c	ft_printf_utils.c \

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