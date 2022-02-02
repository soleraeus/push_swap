/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:15:45 by bdetune           #+#    #+#             */
/*   Updated: 2022/02/02 19:25:35 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	connect_rm(t_info *info, char st, int size, t_list *swap)
{
	t_list	**begin;
	t_list	**last;

	if (!(st == 'A' || st == 'B'))
		return ;
	begin = &info->begin_a;
	last = &info->last_a;
	if (st == 'B')
	{
		begin = &info->begin_b;
		last = &info->last_b;
	}
	if (size == 1)
	{
		*begin = NULL;
		*last = NULL;
		return ;
	}
	*begin = swap->next;
	(*begin)->prev = swap->prev;
	(*last)->next = *begin;
}

static void	connect_ins(t_info *info, char st, int size, t_list **swap)
{
	t_list	**begin;
	t_list	**last;

	if (!(st == 'A' || st == 'B'))
		return ;
	begin = &info->begin_a;
	last = &info->last_a;
	if (st == 'B')
	{
		begin = &info->begin_b;
		last = &info->last_b;
	}
	if (size == 0)
	{
		*last = *swap;
		(*swap)->next = *swap;
	}
	else
	{
		(*swap)->next = *begin;
		(*begin)->prev = *swap;
		(*last)->next = *swap;
	}
	(*swap)->prev = *last;
	*begin = *swap;
}

void	push_b(t_info *info)
{
	t_list	*swap;

	if (info->size_a == 0)
		return ;
	swap = info->begin_a;
	connect_rm(info, 'A', info->size_a, swap);
	connect_ins(info, 'B', info->size_b, &swap);
	info->size_b += 1;
	info->size_a -= 1;
}

void	push_a(t_info *info)
{
	t_list	*swap;

	if (info->size_b == 0)
		return ;
	swap = info->begin_b;
	connect_rm(info, 'B', info->size_b, swap);
	connect_ins(info, 'A', info->size_a, &swap);
	info->size_b -= 1;
	info->size_a += 1;
}
