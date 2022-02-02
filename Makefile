# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdetune <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 17:03:34 by bdetune           #+#    #+#              #
#    Updated: 2022/02/02 20:19:02 by bdetune          ###   ########.fr        #
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

SRCS_BONUS= ./bonus/srcs/checker.c \
			./bonus/srcs/get_next_line.c \
			./bonus/srcs/get_next_line_utils.c \
			./bonus/srcs/info.c \
			./bonus/srcs/inst_lst.c \
			./bonus/srcs/list.c \
			./bonus/srcs/numbers.c \
			./bonus/srcs/push.c \
			./bonus/srcs/rotate.c \
			./bonus/srcs/swap.c

OBJS:=   ${SRCS:.c=.o}

OBJS_BONUS:=   ${SRCS_BONUS:.c=.o}

NAME=		push_swap
INCL:=     ./mandatory/includes/push_swap.h
INCL_BONUS:= ./bonus/includes/checker.h
CC=   		gcc
CFLAGS=   -Wall -Wextra -Werror

${NAME}:	${INCL} ${OBJS}
			${CC} -o ${NAME} ${CFLAGS} ${OBJS} -I mandatory/includes

checker:	${INCL_BONUS} ${OBJS_BONUS}
			${CC} -o checker ${CFLAGS} ${OBJS_BONUS} -I bonus/includes

all:		$(NAME)

bonus:		all checker

${OBJS}:	${INCL}

${OBJS_BONUS} :	${INCL_BONUS}

clean:
		rm -rf ${OBJS} ${OBJS_BONUS}

fclean:		clean
			rm -rf push_swap checker

re:			fclean all

.PHONY:		all clean fclean re bonus

.SECONDARY:	${OBJS} ${OBJS_BONUS}

.c.o:	${INCL}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I mandatory/includes -I bonus/includes
