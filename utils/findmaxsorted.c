/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findmaxsorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:01:50 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/22 04:06:59 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	findmaxsorted(t_info *info)
{
	t_list	*current;

	current = info->begin_a;
	while (current)
	{
		if (current->index == (info->tot_size - 1) && current->streak != -1)
		{
			info->maxsorted = current;
			break;
		}
		current = current->next;
	}
	if (!info->maxsorted)
		info->maxsorted = info->min;
}
