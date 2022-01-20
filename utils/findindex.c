/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findindex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:08:33 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/20 12:23:32 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	findindex(t_info *info)
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
