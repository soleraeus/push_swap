# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdetune <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 17:03:34 by bdetune           #+#    #+#              #
#    Updated: 2022/01/31 20:20:21 by bdetune          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=   ./utils/dist.c \
		./utils/execute_actions.c \
		./utils/find_best_move.c \
		./utils/push_and_swap.c \
		./utils/ft_rotate.c \
		./utils/info.c \
		./utils/init_info.c \
		./utils/insert_btoa.c \
		./utils/list.c \
		./utils/moves.c \
		./utils/numbers.c \
		./utils/optimize_rotations.c \
		./utils/push_or_swap.c \
		./utils/sort.c \
		push_swap.c


OBJS:=   ${SRCS:.c=.o}

NAME=		push_swap
INCL:=     ./includes/push_swap.h
CC=   		gcc
CFLAGS=   -Wall -Wextra -Werror

${NAME}:	${INCL} ${OBJS}
			${CC} -o ${NAME} ${CFLAGS} ${OBJS} -I includes

all:		$(NAME)

${OBJS}:	${INCL}


clean:
		rm -rf ${OBJS}

fclean:		clean
			rm -rf push_swap

re:			fclean all

.PHONY:		all clean fclean re

.SECONDARY:	${OBJS}

.c.o:	${INCL}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I includes
