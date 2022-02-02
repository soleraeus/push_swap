# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdetune <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 17:03:34 by bdetune           #+#    #+#              #
#    Updated: 2022/02/02 18:01:27 by bdetune          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=   ./mandatory/srcs/dist.c \
		./mandatory/srcs/execute_actions.c \
		./mandatory/srcs/find_best_move.c \
		./mandatory/srcs/push.c \
		./mandatory/srcs/swap.c \
		./mandatory/srcs/rotate.c \
		./mandatory/srcs/info.c \
		./mandatory/srcs/init_info.c \
		./mandatory/srcs/insert_btoa.c \
		./mandatory/srcs/list.c \
		./mandatory/srcs/moves.c \
		./mandatory/srcs/numbers.c \
		./mandatory/srcs/optimize_rotations.c \
		./mandatory/srcs/push_or_swap.c \
		./mandatory/srcs/sort.c \
		./mandatory/srcs/push_swap.c


OBJS:=   ${SRCS:.c=.o}

NAME=		push_swap
INCL:=     ./mandatory/includes/push_swap.h
CC=   		gcc
CFLAGS=   -Wall -Wextra -Werror

${NAME}:	${INCL} ${OBJS}
			${CC} -o ${NAME} ${CFLAGS} ${OBJS} -I mandatory/includes

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
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I mandatory/includes
