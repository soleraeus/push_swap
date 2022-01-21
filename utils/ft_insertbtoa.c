/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertbtoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:13:34 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/21 12:14:42 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_findinsertpos(t_info *info, int nb)
{
	int		dist;
	t_list	*current_begin;

	dist = 0;
	current_begin = info->begin_a;
	while (1)
	{
		if (current_begin->prev->nb < nb && (current_begin->nb > nb
				|| current_begin->nb == info->min->nb))
			return (dist);
		current_begin = current_begin->next;
		dist++;
	}
}

void	ft_insertbtoa(t_info *info)
{
	int		i;
	t_moves	*min;
	t_moves	**tab;
	
	while (info->size_b != 0)
	{
		tab = ft_findblocks(info);
		i = 0;
		min = NULL;
		while (tab[i])
		{
			optimize_rotations(info, tab[i], ft_findinsertpos(info, tab[i]->nb), tab[i]->dist);
			tab[i]->pa += 1;
			tot_nb_moves(tab[i]);
			if (!min)
				min = tab[i];
			else if (tab[i]->nb_instructions < min->nb_instructions)
				min = tab[i];
			i++;
		}
		min->pa = min->size_block;
		execute_actions(info, min);
		free_possibilities(tab);
	}
}
