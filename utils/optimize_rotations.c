/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rotations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:09:02 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/25 18:01:07 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	optimize_rotations(t_info *info, t_moves *moves, int dist_a, int dist_b)
{
	int	r_dist_a;
	int	r_dist_b;
	int	tot_pos;
	int	tot_neg;

	r_dist_a = info->size_a - dist_a;
	r_dist_b = info->size_b - dist_b;
	if (dist_b >= dist_a)
		tot_pos = dist_b;
	else
		tot_pos = dist_a;
	if (r_dist_b >= r_dist_a)
		tot_neg = r_dist_b;
	else
		tot_neg = r_dist_a;
	if (tot_neg < (r_dist_a + dist_b) && tot_neg < (dist_a + r_dist_b) && tot_neg <= tot_pos)
	{
		while (!(r_dist_a == 0 || r_dist_b == 0))
		{
			moves->rrr += 1;
			r_dist_a--;
			r_dist_b--;
		}
		moves->dist = info->size_a - r_dist_a;
		ft_bringtofront(info, moves, 'a');
		moves->dist = info->size_b - r_dist_b;
		ft_bringtofront(info, moves, 'b');
	}
	else if (tot_pos < (r_dist_a + dist_b) && tot_pos < (dist_a + r_dist_b) && tot_pos <= tot_neg)
	{
		while (!(dist_a == 0 || dist_b == 0))
		{
			moves->rr += 1;
			dist_a--;
			dist_b--;
		}
		moves->dist = dist_a;
		ft_bringtofront(info, moves, 'a');
		moves->dist = dist_b;
		ft_bringtofront(info, moves, 'b');
	}
	else
	{
		moves->dist = dist_a;
		ft_bringtofront(info, moves, 'a');
		moves->dist = dist_b;
		ft_bringtofront(info, moves, 'b');
	}
}
