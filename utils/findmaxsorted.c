/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findmaxsorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:01:50 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/25 15:56:58 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	findmaxsorted(t_info *info)
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
