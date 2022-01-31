/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_btoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:13:34 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/31 19:06:10 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_ins_pos(t_info *info, t_moves *move)
{
	int		dist;
	t_list	*current;

	if (move->target->index == (info->lst_sz - 1))
		return (getdist(info->begin_a, info->min));
	if (move->target->index == (info->begin_a->index - 1))
		return (0);
	dist = 1;
	current = info->begin_a->next;
	while (current != info->begin_a)
	{
		if (current->index == (move->target->index + 1))
			return (dist);
		current = current->next;
		dist++;
	}
	return (-1);
}

void	nb_pa(t_moves *move, t_list *first)
{
	t_list	*it;

	it = move->target;
	while (it->next && it->next->index == (it->index - 1))
	{
		move->pa += 1;
		it = it->next;
	}
	first->prev->next = first;
}

static t_moves	*get_best_insert(t_info *info, t_list *first)
{
	t_list	*it;
	t_moves	*move;
	t_moves	test;

	move = (t_moves *)malloc(sizeof(t_moves));
	if (!move)
		return (NULL);
	move->target = NULL;
	it = first;
	while (it)
	{
		first->prev->next = first;
		init_mv(&test, it, getdist(info->begin_b, it));
		first->prev->next = NULL;
		optrot(info, &test, get_ins_pos(info, &test), test.dist);
		test.pa += 1;
		tot_nb_moves(&test);
		if (move->target == NULL || test.nb_op < move->nb_op)
			*move = test;
		while (it->next && it->next->index == (it->index - 1))
			it = it->next;
		it = it->next;
	}
	return (nb_pa(move, first), move);
}

t_moves	*ft_insertbtoa(t_info *info, t_moves *mv_lst)
{
	t_list			*first;
	t_moves			*new_mv;

	while (info->size_b != 0)
	{
		first = info->begin_b;
		while (first->prev->index == (first->index + 1))
			first = first->prev;
		new_mv = get_best_insert(info, first);
		if (!new_mv)
			return (free_mv_lst(mv_lst), NULL);
		execute_actions(info, new_mv, 0);
		mv_lst = add_mv(mv_lst, new_mv);
	}
	return (mv_lst);
}
