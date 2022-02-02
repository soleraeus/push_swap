/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rotations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:09:02 by bdetune           #+#    #+#             */
/*   Updated: 2022/02/02 17:51:23 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	combine_rrr(t_info *info, t_moves *mv, int r_dist_a, int r_dist_b)
{
	while (!(r_dist_a == 0 || r_dist_b == 0))
	{
		mv->rrr += 1;
		r_dist_a--;
		r_dist_b--;
	}
	mv->dist = info->size_a - r_dist_a;
	bringtofront(info, mv, 'a');
	mv->dist = info->size_b - r_dist_b;
	bringtofront(info, mv, 'b');
}

static void	combine_rr(t_info *info, t_moves *mv, int dist_a, int dist_b)
{
	while (!(dist_a == 0 || dist_b == 0))
	{
		mv->rr += 1;
		dist_a--;
		dist_b--;
	}
	mv->dist = dist_a;
	bringtofront(info, mv, 'a');
	mv->dist = dist_b;
	bringtofront(info, mv, 'b');
}

static void	seprot(t_info *info, t_moves *mv, int dist_a, int dist_b)
{
	mv->dist = dist_a;
	bringtofront(info, mv, 'a');
	mv->dist = dist_b;
	bringtofront(info, mv, 'b');
}

void	optrot(t_info *info, t_moves *moves, int dist_a, int dist_b)
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
	if (tot_neg < (r_dist_a + dist_b)
		&& tot_neg < (dist_a + r_dist_b) && tot_neg <= tot_pos)
		combine_rrr(info, moves, r_dist_a, r_dist_b);
	else if (tot_pos < (r_dist_a + dist_b)
		&& tot_pos < (dist_a + r_dist_b) && tot_pos <= tot_neg)
		combine_rr(info, moves, dist_a, dist_b);
	else
		seprot(info, moves, dist_a, dist_b);
}
