/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:14:58 by bdetune           #+#    #+#             */
/*   Updated: 2022/02/02 20:19:37 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap(t_list **begin)
{
	t_list	*swap;

	swap = *begin;
	*begin = swap->next;
	(*begin)->next->prev = swap;
	(*begin)->prev = swap->prev;
	(*begin)->prev->next = *begin;
	swap->prev = *begin;
	swap->next = (*begin)->next;
	(*begin)->next = swap;
}

void	swap_one(t_info *info, char st)
{
	t_list	**begin;
	t_list	**last;

	if (!info || !(st == 'A' || st == 'B') || (st == 'A' && info->size_a < 2)
		|| (st == 'B' && info->size_b < 2))
		return ;
	begin = &info->begin_a;
	last = &info->last_a;
	if (st == 'B')
	{
		begin = &info->begin_b;
		last = &info->last_b;
	}
	if ((st == 'A' && info->size_a == 2) || (st == 'B' && info->size_b == 2))
	{
		rot_one(begin, last);
		return ;
	}
	swap(begin);
}

void	swap_both(t_info *info)
{
	swap_one(info, 'A');
	swap_one(info, 'B');
}
