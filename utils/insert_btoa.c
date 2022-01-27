/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_btoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:13:34 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/27 21:09:12 by bdetune          ###   ########.fr       */
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
	t_list	*first;
	t_list	*current;
	int		dist;
	t_moves	*new;
	t_moves	*test;
	t_moves	**tab;

	while (info->size_b != 0)
	{
//		write(1, "OK\n", 3);
		first = info->begin_b;
		while (first->prev->index == (first->index + 1));
			first = first->prev;
		first->prev->next = NULL;
		new = (t_moves *)malloc(sizeof(t_moves));
		new->target = NULL;
		current = first;
		while (current)
		{
			dist = getdist(info->begin_b, info->size_b, current);
			optimize_rotations(info, current, ft_findinsertpos(info, current->nb), tab[i]->dist);
			tab[i]->pa += 1;
			tot_nb_moves(tab[i]);
			if (i == 0)
				*new = *(tab[i]);
			else if (tab[i]->nb_instructions < new->nb_instructions)
				*new = *(tab[i]);
			i++;
		}
		new->pa = new->size_block;
		execute_actions(info, new, 0);
//		instructions = add_instruction(instructions, new);
		free_tab_moves(tab);
	}
	return (instructions);
}
