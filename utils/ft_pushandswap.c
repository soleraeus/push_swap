/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushandswap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:33:41 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/14 20:33:57 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swapone(t_list **begin)
{
	t_list	*swap;

	swap = *begin;
	*begin = (*begin)->next;
	(*begin)->prev = (*begin)->prev->prev;
	(*begin)->prev->next = begin;
	(*begin)->next->prev = swap;
	(*begin)->next = swap;
}

void	ft_swapboth(t_info *info)
{
	ft_swapone(&info->begin_a);
	ft_swapone(&info->begin_b);
}

void	ft_pushb(t_info *info)
{
	t_list	*swap;

	if (info->size_a == 0)
		return ;
	swap = info->begin_a;
	info->begin_a = swap->next;
	info->begin_a->prev = swap->prev;
	info->last_a->next = info->begin_a;
	if (info->size_b == 0)
	{
		info->begin_b = swap;
		info->last_b = swap;
		swap->next = swap;
		swap->prev = swap;
	}
	else
	{
		swap->next = info->begin_b;
		info->begin_b->prev = swap;
		swap->prev = info->last_b;
		info->last_b->next = swap;
		info->begin_b = swap;
	}
	info->size_b += 1;
	info->size_a -= 1;
}

void	ft_pusha(t_info *info)
{
	t_list	*swap;

	if (info->size_b == 0)
		return ;
	swap = info->begin_b;
	if (info->size_b == 1)
	{
		info->begin_b = NULL;
		info->last_b = NULL;
	}
	else
	{
		info->begin_b = swap->next;
		info->begin_b->prev = swap->prev;
		info->last_b->next = info->begin_b;
	}
	swap->next = info->begin_a;
	info->begin_a->prev = swap;
	swap->prev = info->last_a;
	info->last_a->next = swap;
	info->begin_a = swap;
	info->size_b -= 1;
	info->size_a += 1;
}
