/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findindex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:08:33 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/27 14:27:44 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	keep_min_only(t_info *info)
{
	t_list	*current;

	current = info->min->next;
	while (current != info->min)
	{
		current->streak = -1;
		current = current->next;
	}
	info->unordered = info->tot_size - 1;
	info->maxsorted = info->min;
}

void	find_max_sorted(t_info *info)
{
	t_list	*current;

	current = info->begin_a;
	while (current != info->last_a)
	{
		if (current->index == (info->tot_size - 1) && current->streak != -1)
		{
			info->maxsorted = current;
			return ;
		}
		current = current->next;
	}
	if (current->index == (info->tot_size - 1) && current->streak != -1)
		info->maxsorted = current;
	else
		info->maxsorted = info->min;
}

static int	mark_wrong_pos(t_info *info, t_list **start)
{
	t_list	*current;
	t_list	*next;

	current = info->last_a;
	while (current->streak != ((*start)->streak - 1)
		|| current->nb < (*start)->nb)
		current = current->prev;
	next = current;
	current = (*start)->next;
	while (current != next)
	{
		current->streak = -1;
		info->unordered += 1;
		current = current->next;
	}
	if (next->streak != 1)
		return (mark_wrong_pos(info, &next));
	next = next->next;
	while (next != info->min)
	{
		next->streak = -1;
		info->unordered += 1;
		next = next->next;
	}
	return (1);
}

void	find_wrong_pos(t_info *info)
{
	int		max;
	t_list	*current;
	t_list	*cursor;

	info->min->prev->streak = 1;
	current = info->min->prev->prev;
	while (current != info->min->prev)
	{
		max = 0;
		cursor = current->next;
		while (cursor != info->min)
		{
			if (cursor->nb > current->nb && cursor->streak > max)
				max = cursor->streak;
			cursor = cursor->next;
		}
		current->streak = max + 1;
		current = current->prev;
	}
	if (info->min->streak != info->size_a)
		mark_wrong_pos(info, &info->min);
}

void	find_index(t_info *info)
{
	t_list	*current;
	int		maxval;
	t_list	*maxptr;
	int		index;

	index = info->size_a;
	while (index-- > 0)
	{
		current = info->begin_a;
		maxptr = current;
		maxval = INT_MIN;
		while (current)
		{
			if (current->index == -1 && current->nb >= maxval)
			{
				maxval = current->nb;
				maxptr = current;
			}
			current = current->next;
		}
		maxptr->index = index;
	}
}
