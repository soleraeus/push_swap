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

static void	handle_rotates(t_moves *possibility)
{
	while (possibility->ra)
	{
		write(1, "ra\n", 3);
		possibility->ra -= 1;
	}
	while (possibility->rb)
	{
		write(1, "rb\n", 3);
		possibility->rb -= 1;
	}
	while (possibility->rr)
	{
		write(1, "rr\n", 3);
		possibility->rr -= 1;
	}
}

static void	handle_reverse_rotates(t_moves *possibility)
{
	while (possibility->rra)
	{
		write(1, "rra\n", 4);
		possibility->rra -= 1;
	}
	while (possibility->rrb)
	{
		write(1, "rrb\n", 4);
		possibility->rrb -= 1;
	}
	while (possibility->rrr)
	{
		write(1, "rrr\n", 4);
		possibility->rrr -= 1;
	}
}

static void	handle_swaps(t_moves *possibility)
{
	while (possibility->sa)
	{
		write(1, "sa\n", 3);
		possibility->sa -= 1;
	}
	while (possibility->sb)
	{
		write(1, "sb\n", 3);
		possibility->sb -= 1;
	}
}

static void	handle_pushes(t_moves *possibility)
{
	while (possibility->pa)
	{
		write(1, "pa\n", 3);
		possibility->pa -= 1;
	}
	if (possibility->pb)
	{
		write(1, "pb\n", 3);
		possibility->pb -= 1;
	}
}

void	execute_actions(t_instructions *min)
{
	t_instructions	*current;
	t_instructions	*swap;

	current = min->first;
	while (current)
	{
		handle_rotates(current->moves);
		handle_reverse_rotates(current->moves);
		handle_swaps(current->moves);
		handle_pushes(current->moves);
		swap = current->prev;
		free(current->moves);
		free(current);
		current = swap;
	}
}
