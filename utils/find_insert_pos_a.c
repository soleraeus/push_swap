/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_insert_pos_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:49:10 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/21 19:21:23 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_insert_pos_a(t_info *info, t_moves *move, t_list **lower, t_list **upper)
{
	t_list	*current;
	t_list	*current_max;

	current = info->min->prev;
	while (current->streak == -1)
		current = current->prev;
	current_max = current;
	if (move->block_end->index > current_max->index)
	{
		if (move->block_end->index == (current_max->index + 1))
			*lower = current_max->next;
		*upper = info->min;
		return ;
	}
	current = info->begin_a;
	info->last_a->next = NULL;
	while (current && (current->index != (move->target->index + 1)
		|| current->index != (move->block_end->index - 1)))
	{
		if (current->streak != -1 && current->index == (move->target->index + 1))
			*upper = current;
		if (current->streak != -1 && current->index == (move->block_end->index - 1))
			*lower = current;
		current = current->next;
	}
	info->last_a->next = info->begin_a;
	if (*lower)
		*lower = (*lower)->next;
}
