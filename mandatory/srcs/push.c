/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:15:45 by bdetune           #+#    #+#             */
/*   Updated: 2022/02/02 17:36:01 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	connect_rm(t_info *info, char st, int size, t_list *swap)
{
	t_list	**begin;
	t_list	**last;
	t_list	**min;

	if (!(st == 'A' || st == 'B'))
		return ;
	begin = &info->begin_a;
	last = &info->last_a;
	min = &info->min;
	if (st == 'B')
	{
		begin = &info->begin_b;
		last = &info->last_b;
		min = &info->min_b;
	}
	if (size == 1)
	{
		*begin = NULL;
		*last = NULL;
		*min = NULL;
		return ;
	}
	*begin = swap->next;
	(*begin)->prev = swap->prev;
	(*last)->next = *begin;
}

static void	connect_ins(t_info *info, char st, int size, t_list **swap)
{
	t_list	**begin;
	t_list	**last;

	if (!(st == 'A' || st == 'B'))
		return ;
	begin = &info->begin_a;
	last = &info->last_a;
	if (st == 'B')
	{
		begin = &info->begin_b;
		last = &info->last_b;
	}
	if (size == 0)
	{
		*last = *swap;
		(*swap)->next = *swap;
	}
	else
	{
		(*swap)->next = *begin;
		(*begin)->prev = *swap;
		(*last)->next = *swap;
	}
	(*swap)->prev = *last;
	*begin = *swap;
}

void	push_b(t_info *info)
{
	t_list	*swap;

	if (info->size_a == 0)
		return ;
	swap = info->begin_a;
	connect_rm(info, 'A', info->size_a, swap);
	connect_ins(info, 'B', info->size_b, &swap);
	if (!info->min_b || info->min_b->nb > swap->nb)
		info->min_b = swap;
	info->size_b += 1;
	info->size_a -= 1;
}

static void	new_min_b(t_info *info, t_list *swap)
{
	t_list	*min;
	t_list	*current;

	current = swap->next;
	min = current;
	while (current != swap)
	{
		if (current->nb < min->nb)
			min = current;
		current = current->next;
	}
	info->min_b = min;
}

void	push_a(t_info *info)
{
	t_list	*swap;

	if (info->size_b == 0)
		return ;
	swap = info->begin_b;
	if (swap->index == (info->maxsort->index - 1)
		|| (info->maxsort == info->min && swap->index == (info->lst_sz - 1)))
		info->maxsort = swap;
	if (swap == info->min_b && info->size_b > 1)
		new_min_b(info, swap);
	connect_rm(info, 'B', info->size_b, swap);
	connect_ins(info, 'A', info->size_a, &swap);
	info->size_b -= 1;
	info->size_a += 1;
}
