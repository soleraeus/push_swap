/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:01:01 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/22 07:13:31 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_rotates(t_info *info, t_moves *possibility)
{
	while (possibility->ra)
	{
		ft_rotateone(&info->begin_a, &info->last_a);
		write(1, "ra\n", 3);
		possibility->ra -= 1;
	}
	while (possibility->rb)
	{
		ft_rotateone(&info->begin_b, &info->last_b);
		write(1, "rb\n", 3);
		possibility->rb -= 1;
	}
	while (possibility->rr)
	{
		write(1, "rr\n", 3);
		ft_rotateboth(info);
		possibility->rr -= 1;
	}
}

static void	handle_reverse_rotates(t_info *info, t_moves *possibility)
{
	while (possibility->rra)
	{
		ft_reverserotateone(&info->begin_a, &info->last_a);
		write(1, "rra\n", 4);
		possibility->rra -= 1;
	}
	while (possibility->rrb)
	{
		ft_reverserotateone(&info->begin_b, &info->last_b);
		write(1, "rrb\n", 4);
		possibility->rrb -= 1;
	}
	while (possibility->rrr)
	{
		write(1, "rrr\n", 4);
		ft_reverserotateboth(info);
		possibility->rrr -= 1;
	}
}

static void	handle_swaps(t_info *info, t_moves *possibility)
{
	while (possibility->sa)
	{
		ft_swapone(&info->begin_a);
		write(1, "sa\n", 3);
		possibility->sa -= 1;
	}
	while (possibility->sb)
	{
		ft_swapone(&info->begin_b);
		write(1, "sb\n", 3);
		possibility->sb -= 1;
	}
}

static void	handle_pushes(t_info *info, t_moves *possibility)
{
	while (possibility->pa)
	{
		write(1, "pa\n", 3);
		ft_pusha(info);
		possibility->pa -= 1;
	}
	if (possibility->pb)
	{
		write(1, "pb\n", 3);
		ft_pushb(info);
		possibility->pb -= 1;
	}
}

void	execute_actions(t_info *info, t_moves *possibility)
{
	possibility->target->streak = 1;
	handle_rotates(info, possibility);
	handle_reverse_rotates(info, possibility);
	handle_swaps(info, possibility);
	handle_pushes(info, possibility);
}
