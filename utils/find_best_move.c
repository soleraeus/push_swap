/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:41:05 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/31 18:32:04 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tot_nb_moves(t_moves *mv)
{
	mv->nb_op = mv->ra + mv->rb + mv->rr + mv->rra + mv->rrb + mv->rrr \
			+ mv->sa + mv->sb + mv->ss + mv->pa + mv->pb;
	return (mv->nb_op);
}

t_moves	*finalrot(t_info *info, t_moves *mv_lst)
{
	t_moves			*new_mv;

	new_mv = (t_moves *)malloc(sizeof(t_moves));
	if (!new_mv)
		return (free_mv_lst(mv_lst), NULL);
	init_mv(new_mv, info->min, getdist(info->begin_a, info->min));
	ft_bringtofront(info, new_mv, 'a');
	tot_nb_moves(new_mv);
	execute_actions(info, new_mv, 0);
	mv_lst = add_mv(mv_lst, new_mv);
	return (mv_lst);
}

static void	calc_ins_mv(t_info *info, t_moves *ret, int i)
{
	optrot(info, ret, getdist(info->begin_a, info->maxsort), i);
	ret->pa = 1;
	tot_nb_moves(ret);
	ret->target->prev->next = NULL;
	nb_pa(ret, ret->target);
}

t_moves	best_mv_ins(t_info *info)
{
	int		i;
	t_list	*it;
	t_moves	ret;

	ret.target = NULL;
	info->last_b->next = NULL;
	it = info->begin_b;
	i = 0;
	while (it)
	{
		if (it->index == (info->maxsort->index - 1)
			|| (info->maxsort == info->min && it->index == (info->lst_sz - 1)))
		{
			init_mv(&ret, it, i);
			break ;
		}
		i++;
		it = it->next;
	}
	info->last_b->next = info->begin_b;
	if (ret.target)
		calc_ins_mv(info, &ret, i);
	return (ret);
}

t_moves	best_mv_rm(t_info *info)
{
	t_moves	ret;
	t_moves	test;
	t_list	*current;

	ret.target = NULL;
	current = info->min->next;
	while (current != info->min)
	{
		if (current->streak == -1)
		{
			init_mv(&test, current, getdist(info->begin_a, current));
			push_or_swap(info, &test);
			if (ret.target == NULL || test.nb_op < ret.nb_op
				|| (test.nb_op == ret.nb_op && test.nb > ret.nb))
				ret = test;
		}
		current = current->next;
	}
	return (ret);
}
