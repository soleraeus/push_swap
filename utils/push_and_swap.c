/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:59:05 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/31 17:08:17 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_one(t_info *info, char stack)
{
	t_list	**begin;
	t_list	*swap;

	if (!info || !(stack == 'A' || stack == 'B')
		|| (stack == 'A' && info->size_a < 2)
		|| (stack == 'B' && info->size_b < 2))
		return ;
	if (stack == 'A')
		begin = &info->begin_a;
	else
		begin = &info->begin_b;
	swap = *begin;
	if (stack == 'A' && (swap->index == (info->maxsort->index - 1)
			|| (swap->index == (info->lst_sz - 1)
				&& info->maxsort == info->min)))
		info->maxsort = swap;
	if (stack == 'A' && (swap->next->index == (info->maxsort->index - 1)
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

void	ft_pushb(t_info *info)
{
	t_list	*swap;

	if (info->size_a == 0)
		return ;
	swap = info->begin_a;
	info->begin_a = swap->next;
	info->begin_a->prev = swap->prev;
	info->last_a->next = info->begin_a;
	if (info->size_b == 0)
	{
		info->begin_b = swap;
		info->last_b = swap;
		swap->next = swap;
		swap->prev = swap;
	}
	else
	{
		swap->next = info->begin_b;
		info->begin_b->prev = swap;
		swap->prev = info->last_b;
		info->last_b->next = swap;
		info->begin_b = swap;
	}
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
	if (info->size_b == 1)
	{
		info->begin_b = NULL;
		info->last_b = NULL;
		info->min_b = NULL;
	}
	else
	{
		if (swap == info->min_b)
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
		info->begin_b = swap->next;
		info->begin_b->prev = swap->prev;
		info->last_b->next = info->begin_b;
	}
	swap->next = info->begin_a;
	info->begin_a->prev = swap;
	swap->prev = info->last_a;
	info->last_a->next = swap;
	info->begin_a = swap;
	info->size_b -= 1;
	info->size_a += 1;
}
