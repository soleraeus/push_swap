/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushinorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:31:19 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/20 20:05:53 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_pushinorder(t_info *info, t_moves *possibility)
{
	int		nb;
	int		dist_a;
	int		dist_b;
	t_list	*current;

	dist_a = possibility->dist;
	nb = possibility->nb;
	if (info->size_b == 0 || info->size_b == 1)
	{
		ft_bringtofront(info, possibility, 'a');
		possibility->pb += 1;
		return ;
	}
	dist_b = 0;
	current = info->begin_b;
	while (1)
	{
		if ((current->nb < nb
			&& (current->prev->nb > nb || current->prev == info->min_b))
			|| (nb < info->min_b->nb && current->prev == info->min_b) )
			break;
		dist_b++;
		current = current->next;
	}
	optimize_rotations(info, possibility, possibility->dist, dist_b);
	possibility->pb += 1;
}
