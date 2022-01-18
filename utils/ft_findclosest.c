/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findclosest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:59:10 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/18 12:19:42 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*add_possibility(t_info *info, t_list *target, int dist)
{
	t_moves *possibility;

	possibility = (t_moves *)malloc(sizeof(t_moves));
	if (!possibility)
		ft_throwerror(info);
	possibility->target = target;
	possibility->dist = dist;
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
	t_list	*current_last;
	t_list	*current_begin;
	t_moves	**tab;

	if (info->unordered < 20)
		tab = (t_moves **)malloc(sizeof(t_moves *) * (info->unordered + 1));
	else
		tab = (t_moves **)malloc(sizeof(t_moves *) * (21));
	if (!tab)
		ft_throwerror(info);
	found = 0;
	dist = 1;
	if (info->begin_a->streak == -1)
		tab[found++] = add_possibility(info, info->begin_a, 0);
	current_begin = info->begin_a->next;
	current_last = info->last_a;
	while (!(found == 20 || found == info->unordered))
	{
		if (current_begin->streak == -1)
			tab[found++] = add_possibility(info, current_begin, dist);
		if (found == 20 || found == info->unordered)
			break ;
		if (current_last->streak == -1)
			tab[found++] = add_possibility(info, current_last, -dist);
		current_begin = current_begin->next;
		current_last = current_last->prev;
		dist++;
	}
	tab[found] = NULL;
	return (tab);
}

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
