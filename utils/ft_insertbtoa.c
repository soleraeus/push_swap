/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertbtoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:13:34 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/22 08:27:39 by bdetune          ###   ########.fr       */
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

t_instructions	*ft_insertbtoa(t_info *info, t_instructions *instructions)
{
	int		i;
	t_moves	*new;
	t_moves	**tab;
	
	while (info->size_b != 0)
	{
		tab = ft_findblocks(info);
		i = 0;
		new = (t_moves *)malloc(sizeof(t_moves));
		while (tab[i])
		{
			optimize_rotations(info, tab[i], ft_findinsertpos(info, tab[i]->nb), tab[i]->dist);
			tab[i]->pa += 1;
			tot_nb_moves(tab[i]);
			if (i == 0)
				*new = *(tab[i]);
			else if (tab[i]->nb_instructions < new->nb_instructions)
				*new = *(tab[i]);
			i++;
		}
		new->pa = new->size_block;
		execute_actions(info, new);
		instructions = add_instruction(instructions, new);
		free_possibilities(tab);
	}
	return (instructions);
}
