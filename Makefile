# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 10:57:08 by balnahdi          #+#    #+#              #
#    Updated: 2022/04/06 10:57:09 by balnahdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = ./create_map.c ./main.c ./validate_map.c ./free.c ./map_elem.c ./img.c ./key.c

BSRC = ./create_map_b.c ./main_b.c ./validate_map_b.c ./free_b.c ./map_elem_b.c ./img_b.c ./key_b.c

OBJS = ${SRC:.c=.o}

OBJS = ${BSRC:.c=.o}

FLAGS = -Wall -Wextra -Werror

LINKS = -Lmlx -lmlx -framework OpenGl -framework Appkit

CC = gcc

RM = rm -rf

bouns :
	${MAKE} -C ./mlx
	${MAKE} -C ./ft_printf
	${MAKE} -C ./get_next_line
	${CC} ${FLAGS} ${LINKS} ${BSRC} ./get_next_line/gnl.a ./ft_printf/libftprintf.a -o ${NAME}	

$(NAME): $(OBJS)
	${MAKE} -C ./mlx
	${MAKE} -C ./ft_printf
	${MAKE} -C ./get_next_line
	${CC} ${FLAGS} ${LINKS} ${SRC} ./get_next_line/gnl.a ./ft_printf/libftprintf.a -o ${NAME}

all : ${NAME}

clean:
	${RM} ${OBJS}
	${MAKE} clean -C ./ft_printf
	${MAKE} clean -C ./get_next_line
	${MAKE} clean -C ./mlx

fclean: clean
	${RM} ./so_long
	${MAKE} clean -C ./mlx
	${MAKE} fclean -C ./ft_printf
	${MAKE} fclean -C ./get_next_line

re: fclean all

.PHONY: all clean fclean re