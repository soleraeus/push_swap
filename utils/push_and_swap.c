/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:59:05 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/31 18:08:44 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_one(t_info *info, char st)
{
	t_list	**begin;
	t_list	*swap;

	if (!info || !(st == 'A' || st == 'B') || (st == 'A' && info->size_a < 2)
		|| (st == 'B' && info->size_b < 2))
		return ;
	begin = &info->begin_a;
	if (st == 'B')
		begin = &info->begin_b;
	swap = *begin;
	if (st == 'A' && (swap->index == (info->maxsort->index - 1)
			|| (swap->index == (info->lst_sz - 1)
				&& info->maxsort == info->min)))
		info->maxsort = swap;
	if (st == 'A' && (swap->next->index == (info->maxsort->index - 1)
			|| (swap->next->index == (info->lst_sz - 1)
				&& info->maxsort == info->min)))
		info->maxsort = swap->next;
	*begin = swap->next;
	(*begin)->next->prev = swap;
	(*begin)->prev = swap->prev;
	(*begin)->prev->next = *begin;
	swap->prev = *begin;
	swap->next = (*begin)->next;
	(*begin)->next = swap;
}

void	swap_both(t_info *info)
{
	swap_one(info, 'A');
	swap_one(info, 'B');
}

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

void	ft_pushb(t_info *info)
{
	t_list	*swap;

	if (info->size_a == 0)
		return ;
	swap = info->begin_a;
	connect_rm(info, 'A', info->size_a, swap);
	if (info->size_b == 0)
	{
		info->last_b = swap;
		swap->next = swap;
	}
	else
	{
		swap->next = info->begin_b;
		info->begin_b->prev = swap;
		info->last_b->next = swap;
	}
	swap->prev = info->last_b;
	info->begin_b = swap;
	if (!info->min_b || info->min_b->nb > swap->nb)
		info->min_b = swap;
	info->size_b += 1;
	info->size_a -= 1;
}

void	ft_pusha(t_info *info)
{
	t_list	*min;
	t_list	*swap;
	t_list	*current;

	if (info->size_b == 0)
		return ;
	swap = info->begin_b;
	if (swap->index == (info->maxsort->index - 1)
		|| (info->maxsort == info->min && swap->index == (info->lst_sz - 1)))
		info->maxsort = swap;
	if (swap == info->min_b && info->size_b > 1)
	{
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
	connect_rm(info, 'B', info->size_b, swap);
	if (info->size_a == 0)
	{
		info->last_a = swap;
		swap->next = swap;
	}
	else
	{
		swap->next = info->begin_a;
		info->begin_a->prev = swap;
		info->last_a->next = swap;
	}
	swap->prev = info->last_a;
	info->begin_a = swap;
	info->size_b -= 1;
	info->size_a += 1;
}
