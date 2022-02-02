/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:32:43 by bdetune           #+#    #+#             */
/*   Updated: 2022/02/02 19:27:18 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	find_index(t_info *info)
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

static void	init_info(t_info *info, int size)
{
	info->begin_a = NULL;
	info->last_a = NULL;
	info->size_a = size;
	info->begin_b = NULL;
	info->last_b = NULL;
	info->size_b = 0;
	info->lst_sz = size;
}

void	free_info(t_info *info)
{
	free_list(info->begin_a);
	free_list(info->begin_b);
	free(info);
}

int	create_info(t_info *info, int ac, char **av)
{
	init_info(info, (ac - 1));
	while (ac-- > 1)
	{
		if (lstaddnbr(info, av[ac]))
			return (1);
	}
	find_index(info);
	info->begin_a->prev = info->last_a;
	info->last_a->next = info->begin_a;
	return (0);
}
