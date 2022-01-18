/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:01:01 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/18 14:12:57 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_actions(t_info *info, t_moves *possibility)
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
		ft_rotateboth(info);
		possibility->rr -= 1;
	}
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
		ft_reverserotateboth(info);
		possibility->rrr -= 1;
	}
	if (possibility->sa)
	{
		ft_swapone(&info->begin_a);
		write(1, "sa\n", 3);
	}
	if (possibility->sb)
	{
		ft_swapone(&info->begin_b);
		write(1, "sb\n", 3);
	}
	if (possibility->pa)
		ft_pusha(info);
	if (possibility->pb)
		ft_pushb(info);
}
