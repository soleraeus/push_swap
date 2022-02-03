/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:14:58 by bdetune           #+#    #+#             */
/*   Updated: 2022/02/03 13:21:02 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_swap(t_list **begin)
{
	t_list	*swap;

	swap = *begin;
	*begin = swap->next;
	(*begin)->next->prev = swap;
	(*begin)->prev = swap->prev;
	(*begin)->prev->next = *begin;
	swap->prev = *begin;
	swap->next = (*begin)->next;
	(*begin)->next = swap;
}

static void	update_maxsort(t_info *info)
{
	t_list	*swap;

	swap = info->begin_a;
	if (swap->index == (info->maxsort->index - 1)
		|| (swap->index == (info->lst_sz - 1) && info->maxsort == info->min))
		info->maxsort = swap;
	if (swap->next->index == (info->maxsort->index - 1)
		|| (swap->next->index == (info->lst_sz - 1)
			&& info->maxsort == info->min))
		info->maxsort = swap->next;
}

void	swap_one(t_info *info, char st)
{
	t_list	**begin;
	t_list	**last;

	if (!info || !(st == 'A' || st == 'B') || (st == 'A' && info->size_a < 2)
		|| (st == 'B' && info->size_b < 2))
		return ;
	begin = &info->begin_a;
	last = &info->last_a;
	if (st == 'B')
	{
		begin = &info->begin_b;
		last = &info->last_b;
	}
	if (st == 'A')
		update_maxsort(info);
	if ((st == 'A' && info->size_a == 2) || (st == 'B' && info->size_b == 2))
		rot_one(begin, last);
	else
		make_swap(begin);
}

void	swap_both(t_info *info)
{
	swap_one(info, 'A');
	swap_one(info, 'B');
}
