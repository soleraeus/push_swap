/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 07:16:56 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/22 07:17:32 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_rotates(t_info *info, t_moves *possibility)
{
	while (possibility->ra)
	{
		ft_rotateone(&info->begin_a, &info->last_a);
		possibility->ra -= 1;
	}
	while (possibility->rb)
	{
		ft_rotateone(&info->begin_b, &info->last_b);
		possibility->rb -= 1;
	}
	while (possibility->rr)
	{
		ft_rotateboth(info);
		possibility->rr -= 1;
	}
}

static void	handle_reverse_rotates(t_info *info, t_moves *possibility)
{
	while (possibility->rra)
	{
		ft_reverserotateone(&info->begin_a, &info->last_a);
		possibility->rra -= 1;
	}
	while (possibility->rrb)
	{
		ft_reverserotateone(&info->begin_b, &info->last_b);
		possibility->rrb -= 1;
	}
	while (possibility->rrr)
	{
		ft_reverserotateboth(info);
		possibility->rrr -= 1;
	}
}

static void	handle_swaps(t_info *info, t_moves *possibility)
{
	while (possibility->sa)
	{
		ft_swapone(&info->begin_a);
		possibility->sa -= 1;
	}
	while (possibility->sb)
	{
		ft_swapone(&info->begin_b);
		possibility->sb -= 1;
	}
}

static void	handle_pushes(t_info *info, t_moves *possibility)
{
	while (possibility->pa)
	{
		ft_pusha(info);
		possibility->pa -= 1;
	}
	if (possibility->pb)
	{
		ft_pushb(info);
		possibility->pb -= 1;
	}
}

void	simulate_actions(t_info *info, t_moves *possibility)
{
	t_moves	*possibility_cpy;

	possibility_cpy = cpy_move(possibility);
	possibility->target->streak = 1;
	handle_rotates(info, possibility_cpy);
	handle_reverse_rotates(info, possibility_cpy);
	handle_swaps(info, possibility_cpy);
	handle_pushes(info, possibility_cpy);
}
