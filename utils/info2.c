/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:32:18 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/27 12:33:14 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*lst_addfront(t_list *begin, t_list *current)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->nb = current->nb;
	new->index = current->index;
	new->streak = current->streak;
	new->next = begin;
	new->prev = NULL;
	if (begin)
		begin->prev = new;
	return (new);
}

static void	cpy_info(t_info *dst, t_info *src)
{
	t_list	*current;

	dst->unordered = src->unordered;
	current = src->last_a;
	while (current != src->begin_a)
	{
		dst->begin_a = lst_addfront(dst->begin_a, current);
		if (current == src->last_a)
			dst->last_a = dst->begin_a;
		if (current == src->min)
			dst->min = dst->begin_a;
		if (current == src->maxsorted)
			dst->maxsorted = dst->begin_a;
		current = current->prev;
	}
	dst->begin_a = lst_addfront(dst->begin_a, current);
	if (current == src->min)
		dst->min = dst->begin_a;
	if (current == src->maxsorted)
		dst->maxsorted = dst->begin_a;
	dst->begin_a->prev = dst->last_a;
	dst->last_a->next = dst->begin_a;
}
