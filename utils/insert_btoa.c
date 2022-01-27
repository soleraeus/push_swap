/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_btoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:13:34 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/27 21:09:12 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findinsertpos(t_info *info, t_moves *move)
{
	int	dist;
	t_list	*current;

	if (move->target->index == (info->tot_size - 1))
		return (getdist(info->begin_a, info->size_a, info->min));
	if (move->target->index == (info->begin_a->index - 1))
		return (0);
	dist = 1;
	current = info->begin_a->next;
	while (current != info->begin_a)
	{
		if (current->index == (move->target->index + 1))
			return (dist);
		current = current->next;
		dist++;
	}
	return (-1);
}

t_instructions	*ft_insertbtoa(t_info *info, t_instructions *instructions)
{
	t_list	*first;
	t_list	*current;
	int		dist;
	t_moves	*new;
	t_moves	test;

	while (info->size_b != 0)
	{
		first = info->begin_b;
		while (first->prev->index == (first->index + 1))
			first = first->prev;
		new = (t_moves *)malloc(sizeof(t_moves));
		if (!new)
			return (free_instructions(instructions), NULL);
		new->target = NULL;
		current = first;
		while (current)
		{
			first->prev->next = first;	
			dist = getdist(info->begin_b, info->size_b, current);
			first->prev->next = NULL;
			init_existing_move(&test, current, dist);
			optimize_rotations(info, &test, findinsertpos(info, &test), dist);
			test.pa += 1;
			tot_nb_moves(&test);
			if (new->target == NULL)
				*new = test;
			else if (test.nb_instructions < new->nb_instructions)
				*new = test;
			while (current->next && current->next->index == (current->index - 1))
				current = current->next;
			current = current->next;
		}
		current = new->target;
		while (current->next && current->next->index == (current->index - 1))
		{
			new->pa += 1;
			current = current->next;
		}
		first->prev->next = first;
		execute_actions(info, new, 0);
		instructions = add_instruction(instructions, new);
	}
	return (instructions);
}
