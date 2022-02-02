/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 07:16:56 by bdetune           #+#    #+#             */
/*   Updated: 2022/02/02 17:42:52 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_rotates(t_info *info, t_moves *move, int print)
{
	int	ra;
	int	rb;
	int	rr;

	ra = move->ra;
	rb = move->rb;
	rr = move->rr;
	if (!print)
	{
		while (ra--)
			rot_one(&info->begin_a, &info->last_a);
		while (rb--)
			rot_one(&info->begin_b, &info->last_b);
		while (rr--)
			rot_both(info);
		return ;
	}
	while (ra--)
		write(1, "ra\n", 3);
	while (rb--)
		write(1, "rb\n", 3);
	while (rr--)
		write(1, "rr\n", 3);
}

static void	handle_reverse_rotates(t_info *info, t_moves *move, int print)
{
	int	rra;
	int	rrb;
	int	rrr;

	rra = move->rra;
	rrb = move->rrb;
	rrr = move->rrr;
	if (!print)
	{
		while (rra--)
			rev_rot_one(&info->begin_a, &info->last_a);
		while (rrb--)
			rev_rot_one(&info->begin_b, &info->last_b);
		while (rrr--)
			rev_rot_both(info);
		return ;
	}
	while (rra--)
		write(1, "rra\n", 4);
	while (rrb--)
		write(1, "rrb\n", 4);
	while (rrr--)
		write(1, "rrr\n", 4);
}

static void	handle_swaps(t_info *info, t_moves *move, int print)
{
	int	sa;
	int	sb;
	int	ss;

	sa = move->sa;
	sb = move->sb;
	ss = move->ss;
	if (!print)
	{
		while (sa--)
			swap_one(info, 'A');
		while (sb--)
			swap_one(info, 'B');
		while (ss--)
			swap_both(info);
		return ;
	}
	while (sa--)
		write(1, "sa\n", 3);
	while (sb--)
		write(1, "sb\n", 3);
	while (ss--)
		write(1, "ss\n", 3);
}

static void	handle_pushes(t_info *info, t_moves *move, int print)
{
	int	pa;
	int	pb;

	pa = move->pa;
	pb = move->pb;
	if (!print)
	{
		while (pa--)
			push_a(info);
		while (pb--)
			push_b(info);
		return ;
	}
	while (pa--)
		write(1, "pa\n", 3);
	while (pb--)
		write(1, "pb\n", 3);
}

void	execute_actions(t_info *info, t_moves *move, int print)
{
	move->target->streak = 1;
	handle_rotates(info, move, print);
	handle_reverse_rotates(info, move, print);
	handle_swaps(info, move, print);
	handle_pushes(info, move, print);
}
