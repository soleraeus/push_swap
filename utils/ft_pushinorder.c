/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushinorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:31:19 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/17 14:58:09 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_pushinorder(t_info *info, int dist_a, int nb)
{
	int		dist_b;
	t_list	*current;

//	printf("nb : %d\n", nb);
//	printf("OK push in order\n");
	if (info->size_b == 0 || info->size_b == 1)
	{
		ft_bringtofront(info, dist_a, 'a');
		ft_pushb(info);
		return ;
	}
//	printf("min B: %d\n", info->min_b->nb);
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
//	printf("dist B: %d\n", dist_b);
//	printf("size B: %d\n", info->size_b);
//	printf("reverse dist B: %d\n", -(info->size_b - dist_b));
//	printf("dist A: %d\n", dist_a);
	if (dist_a < 0 && (info->size_b - dist_b) < dist_b)
	{
		dist_b = -(info->size_b - dist_b);
		while (!(dist_a == 0 || dist_b == 0))
		{
			ft_reverserotateboth(info);
			dist_a++;
			dist_b++;
		}
		ft_bringtofront(info, dist_a, 'a');
		ft_bringtofront(info, dist_b, 'b');
	}
	else if (dist_a > 0 && (info->size_b - dist_b) > dist_b)
	{
//		write(1, "case 2\n", 7);
		while (!(dist_a == 0 || dist_b == 0))
		{
			ft_rotateboth(info);
			dist_a--;
			dist_b--;
		}
		ft_bringtofront(info, dist_a, 'a');
		ft_bringtofront(info, dist_b, 'b');
	}
	else if (dist_a < 0 && (dist_a <= -(info->size_b - dist_b)
			   || -(-(info->size_b - dist_b) - dist_a) < dist_b))
	{
		dist_b = -(info->size_b - dist_b);
		while (!(dist_a == 0 || dist_b == 0))
		{
			ft_reverserotateboth(info);
			dist_a++;
			dist_b++;
		}
		ft_bringtofront(info, dist_a, 'a');
		ft_bringtofront(info, dist_b, 'b');
	}
	else if (dist_a > 0 && (dist_a > dist_b
			   || (dist_b - dist_a) < (info->size_b - dist_b) ))
	{
//		write(1, "OK\n", 3);
		while (!(dist_a == 0 || dist_b == 0))
		{
			ft_rotateboth(info);
			dist_a--;
			dist_b--;
		}
		ft_bringtofront(info, dist_a, 'a');
		ft_bringtofront(info, dist_b, 'b');
	}
	else
	{
		ft_bringtofront(info, dist_a, 'a');
		if (dist_b < (info->size_b - dist_b))
			ft_bringtofront(info, dist_b, 'b');
		else
			ft_bringtofront(info, (-(info->size_b - dist_b)), 'b');
	}
	ft_pushb(info);
}
