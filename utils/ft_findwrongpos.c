/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findwrongpos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:06:31 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/15 13:10:47 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_markwrongpos(t_info *info, t_list **start)
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
		return (ft_markwrongpos(info, &next));
	next = next->next;
	while (next != info->min)
	{
		next->streak = -1;
		info->unordered += 1;
		next = next->next;
	}
	return (1);
}

void	ft_findwrongpos(t_info *info)
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
		ft_markwrongpos(info, &info->min);
}
