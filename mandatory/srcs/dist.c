/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:28:00 by bdetune           #+#    #+#             */
/*   Updated: 2022/02/02 17:48:06 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getdist(t_list *begin, t_list *target)
{
	int		dist;
	t_list	*current;

	dist = 0;
	current = begin;
	while (current != target)
	{
		dist++;
		current = current->next;
	}
	return (dist);
}

void	bringtofront(t_info *info, t_moves *possibility, char stack)
{
	int	dist;

	dist = possibility->dist;
	if (stack == 'a' && (info->size_a - dist) < dist)
		dist = -(info->size_a - dist);
	if (stack == 'b' && (info->size_b - dist) < dist)
		dist = -(info->size_b - dist);
	while (dist < 0)
	{
		if (stack == 'a')
			possibility->rra += 1;
		else
			possibility->rrb += 1;
		dist++;
	}
	while (dist > 0)
	{
		if (stack == 'a')
			possibility->ra += 1;
		else
			possibility->rb += 1;
		dist--;
	}
}
