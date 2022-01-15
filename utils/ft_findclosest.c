/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findclosest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:59:10 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/15 16:38:26 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findclosest(t_info *info, t_list **unordered)
{
	int		dist;
	t_list	*current_last;
	t_list	*current_begin;

	if (info->begin_a->streak == -1)
	{
		*unordered = info->begin_a;
		return (0);
	}
	current_begin = info->begin_a->next;
	current_last = info->last_a;
	dist = 1;
	while (1)
	{
		if (current_begin->streak == -1)
		{
			*unordered = current_begin;
			return (dist);
		}
		if (current_last->streak == -1)
		{
			*unordered = current_last;
			return (-dist);
		}
		dist++;
		current_begin = current_begin->next;
		current_last = current_last->prev;
	}
}
