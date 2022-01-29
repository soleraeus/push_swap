/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_possibilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:59:10 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/29 10:48:24 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	create_insert_pos_tab(t_info *info, t_moves ***tab, t_list **first)
{
	int		nb_blocks;
	t_list	*current;

	nb_blocks = 1;
	if (info->size_b == 1)
	{
		*tab = (t_moves **)malloc(sizeof(t_moves) * 2);
		*first = info->begin_b;
		return (1);
	}
	current = info->begin_b;
	while (current->prev != info->begin_b
		&& current->index == (current->prev->index - 1))
		current = current->prev;
	*first = current;
	current = current->next;
	while (current != *first)
	{
		if (current->index != (current->prev->index - 1))
			nb_blocks++;
		current = current->next;
	}
	*tab = (t_moves **)malloc(sizeof(t_moves *) * (nb_blocks + 1));
	return (nb_blocks);
}

static t_list	*end_of_block(t_list *begin)
{
	t_list	*current;

	current = begin;
	while (current->next->index == (current->index - 1))
		current = current->next;
	return (current);
}

static int	addblocks(t_info *info, t_moves **tab, int nb_blocks)
{
	int		index;
	int		dist_target;
	int		end_dist;
	t_list	*current;

	index = 1;
	while (index < nb_blocks)
	{
		current = tab[(index - 1)]->block_end->next;
		dist_target = getdist(info->begin_b, info->size_b, current);
		tab[index] = add_move(current, dist_target);
		if (!tab[index])
			return (free_tab_moves(tab), 1);
		tab[index]->block_end = end_of_block(current);
		end_dist = getdist(info->begin_b, info->size_b, tab[index]->block_end);
		tab[index]->size_block += end_dist - tab[index]->dist;
		index++;
	}
	return (0);
}

t_moves	**find_blocks(t_info *info)
{
	int		nb_blocks;
	t_list	*first;
	t_moves	**tab;

	nb_blocks = create_insert_pos_tab(info, &tab, &first);
	if (!tab)
		return (NULL);
	tab[0] = add_move(first, getdist(info->begin_b, info->size_b, first));
	if (!tab[0])
		return (free(tab), NULL);
	tab[nb_blocks] = NULL;
	tab[0]->block_end = end_of_block(first);
	tab[0]->size_block = getdist(info->begin_b, info->size_b, tab[0]->block_end);
	if (tab[0]->dist != 0)
		tab[0]->size_block += (info->size_b - tab[0]->dist);
	if (addblocks(info, tab, nb_blocks))
		return (NULL);
	return (tab);
}
