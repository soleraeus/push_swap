/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:49:39 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/31 19:19:23 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*add_mv(t_moves *mv_lst, t_moves *new_mv)
{
	if (!new_mv)
		return (mv_lst);
	tot_nb_moves(new_mv);
	if (mv_lst)
	{
		mv_lst->prev = new_mv;
		new_mv->first = mv_lst->first;
		new_mv->nb_op += mv_lst->nb_op;
	}
	else
		new_mv->first = new_mv;
	return (new_mv);
}

void	print_mv_lst(t_moves *mv_lst)
{
	t_moves	*it;
	t_moves	*prev;

	if (!mv_lst)
		return ;
	it = mv_lst->first;
	while (it)
	{
		execute_actions(NULL, it, 1);
		prev = it->prev;
		free(it);
		it = prev;
	}
}

void	free_mv_lst(t_moves *mv_lst)
{
	t_moves	*it;
	t_moves	*prev;

	if (!mv_lst)
		return ;
	it = mv_lst->first;
	while (it)
	{
		prev = it->prev;
		free(it);
		it = prev;
	}
}

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
	move->prev = NULL;
	move->first = NULL;
}
