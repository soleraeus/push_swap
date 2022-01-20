/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertbtoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:13:34 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/20 19:42:48 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_findinsertpos(t_info *info, int nb)
{
	int		dist;
	t_list	*current_begin;

	dist = 0;
	current_begin = info->begin_a->next;
	while (1)
	{
		if (current_begin->prev->nb < nb && (current_begin->nb > nb
				|| current_begin->nb == info->min->nb))
			return (dist);
		current_begin = current_begin->next;
		dist++;
	}
}

void	ft_insertbtoa(t_info *info)
{
	t_moves	*target;
	
	target = (t_moves *)malloc(sizeof(t_moves));
	if (!target)
		ft_throwerror(info);
	while (info->size_b != 0)
	{
		target->target = info->begin_b;
		target->nb = target->target->nb;
		target->dist = ft_findinsertpos(info, target->nb);
		init_target(target);
		ft_bringtofront(info, target, 'a');
		target->pa = 1;
		execute_actions(info, target);
	}
	free(target);
}
