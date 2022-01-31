/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:49:39 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/31 16:50:16 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_mv(t_moves *move, t_list *target, int dist)
{
	move->target = target;
	move->dist = dist;
	move->nb = target->nb;
	move->nb_op = 0;
	move->ra = 0;
	move->rb = 0;
	move->rr = 0;
	move->rra = 0;
	move->rrb = 0;
	move->rrr = 0;
	move->sa = 0;
	move->sb = 0;
	move->ss = 0;
	move->pa = 0;
	move->pb = 0;
}
