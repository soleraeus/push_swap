# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdetune <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 17:03:34 by bdetune           #+#    #+#              #
#    Updated: 2022/01/25 16:46:13 by bdetune          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=   ./utils/ft_atoll.c \
		./utils/ft_checknb.c \
		./utils/ft_freelst.c \
		./utils/ft_isdigit.c \
		./utils/ft_lstaddnbr.c \
		./utils/ft_throwerror.c \
		./utils/ft_checkdouble.c \
		./utils/findindex.c \
		./utils/ft_rotate.c \
		./utils/ft_pushandswap.c \
		./utils/ft_finalrotation.c \
		./utils/ft_initinfo.c \
		./utils/ft_findwrongpos.c \
		./utils/ft_bringtopos.c \
		./utils/ft_find_val.c \
		./utils/ft_findclosest.c \
		./utils/ft_pushinorder.c \
		./utils/canswap.c \
		./utils/init_target.c \
		./utils/ft_insertbtoa.c \
		./utils/execute_actions.c \
		./utils/free_possibilities.c \
		./utils/optimize_rotations.c \
		./utils/findmaxsorted.c \
		./utils/simulate_actions.c \
		./utils/add_instruction.c \
		./utils/cpy_move.c \
		./utils/cpy_info.c \
		./utils/keep_min_only.c \
		push_swap.c


OBJS:=   ${SRCS:.c=.o}

NAME=		push_swap
INCL:=     ./includes/push_swap.h
CC=   		gcc
CFLAGS=   -Wall -Wextra -Werror

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
