/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findclosest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:59:10 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/21 12:14:53 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_moves	*add_possibility(t_info *info, t_list *target, int dist)
{
	t_moves *possibility;

	possibility = (t_moves *)malloc(sizeof(t_moves));
	if (!possibility)
		ft_throwerror(info);
	possibility->target = target;
	possibility->block_end = NULL;
	possibility->dist = dist;
	possibility->size_block = 1;
	possibility->nb = target->nb;
	possibility->nb_instructions = 0;
	possibility->ra = 0;
	possibility->rb = 0;
	possibility->rr = 0;
	possibility->rra = 0;
	possibility->rrb = 0;
	possibility->rrr = 0;
	possibility->sa = 0;
	possibility->sb = 0;
	possibility->ss = 0;
	possibility->pa = 0;
	possibility->pb = 0;
	return (possibility);
}

t_moves	**ft_findtargets(t_info *info)
{
	int		found;
	int		dist;
	t_list	*current_begin;
	t_moves	**tab;

	if (info->unordered < TARGET_NB)
		tab = (t_moves **)malloc(sizeof(t_moves *) * (info->unordered + 1));
	else
		tab = (t_moves **)malloc(sizeof(t_moves *) * (TARGET_NB + 1));
	if (!tab)
		ft_throwerror(info);
	found = 0;
	dist = 0;
	current_begin = info->begin_a;
	while (!(found == TARGET_NB || found == info->unordered))
	{
		if (current_begin->streak == -1)
			tab[found++] = add_possibility(info, current_begin, dist);
		current_begin = current_begin->next;
		dist++;
	}
	tab[found] = NULL;
	return (tab);
}

int	create_insert_pos_tab(t_info *info, t_moves ***tab, t_list **first)
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
	while (current->prev != info->begin_b && current->index == (current->prev->index - 1))
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

int	getdist(t_list *begin, int size, t_list *target)
{
	int		dist;
	t_list	*current;

	(void)size;
	dist = 0;
	current = begin;
	while (current != target)
	{
		dist++;
		current = current->next;
	}
	return (dist);
}

t_list	*find_end_of_block(t_list *begin)
{
	t_list	*current;

	current = begin;
	while (current->next->index == (current->index - 1))
		current = current->next;
	return (current);
}

void	addblocks(t_info *info, t_moves **tab, t_list *first, int nb_blocks)
{
	int		index;
	t_list	*current;

	index = 0;
	tab[index] = add_possibility(info, first, getdist(info->begin_b, info->size_b, first));
	tab[index]->block_end = find_end_of_block(first);
	tab[index]->dist = getdist(info->begin_b, info->size_b, tab[index]->target);
	if (tab[index]->dist != 0)
		tab[index]->size_block += (info->size_b - tab[index]->dist) + getdist(info->begin_b, info->size_b, tab[index]->block_end);
	else
		tab[index]->size_block += getdist(info->begin_b, info->size_b, tab[index]->block_end);
	index++;
	while (index < nb_blocks)
	{
		current = tab[(index - 1)]->block_end->next;
		tab[index] = add_possibility(info, current, getdist(info->begin_b, info->size_b, current));
		tab[index]->block_end = find_end_of_block(current);
		tab[index]->dist = getdist(info->begin_b, info->size_b, tab[index]->target);
		tab[index]->size_block += getdist(info->begin_b, info->size_b, tab[index]->block_end) - tab[index]->dist;
		index++;
	}
}

t_moves	**ft_findblocks(t_info *info)
{
	int		nb_blocks;
	t_list	*first;
	t_moves	**tab;

	nb_blocks = create_insert_pos_tab(info, &tab, &first);
	if (!tab)
		ft_throwerror(info);
	tab[nb_blocks] = NULL;
	addblocks(info, tab, first, nb_blocks);
	return (tab);
}
