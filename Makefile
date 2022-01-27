# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdetune <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 17:03:34 by bdetune           #+#    #+#              #
#    Updated: 2022/01/27 20:25:37 by bdetune          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=   ./utils/build_possibilities.c \
		./utils/dist.c \
		./utils/execute_actions.c \
		./utils/find_best_move.c \
		./utils/ft_finalrotation.c \
		./utils/ft_pushandswap.c \
		./utils/ft_rotate.c \
		./utils/info.c \
		./utils/init_info.c \
		./utils/insert_btoa.c \
		./utils/instructions.c \
		./utils/list.c \
		./utils/moves.c \
		./utils/numbers.c \
		./utils/optimize_rotations.c \
		./utils/pushorswap.c \
		./utils/sort.c \
		./utils/throw_error.c \
		push_swap.c


OBJS:=   ${SRCS:.c=.o}

NAME=		push_swap
INCL:=     ./includes/push_swap.h
CC=   		gcc
CFLAGS=   -Wall -Wextra -Werror -fsanitize=address

${NAME}:	${INCL} ${OBJS}
			${CC} -o ${NAME} ${CFLAGS} ${OBJS} -I includes

all:		${NAME}

clean:
		rm -rf ${OBJS}

fclean:		clean
			rm -rf push_swap

re:			fclean all

.PHONY:		all clean fclean re

.c.o:	${INCL}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I includes
