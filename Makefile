# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdetune <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 17:03:34 by bdetune           #+#    #+#              #
#    Updated: 2022/01/10 21:22:12 by bdetune          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=   ./utils/ft_atoi.c \
		./utils/ft_checknb.c \
		./utils/ft_freelst.c \
		./utils/ft_isdigit.c \
		./utils/ft_lstaddnbr.c \
		./utils/ft_throwerror.c \
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

.c.o:	
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I includes


