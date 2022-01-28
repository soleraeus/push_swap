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

int	get_ins_pos(t_info *info, t_moves *move)
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

static void	nb_pa(t_moves *new, t_list *first)
{
	t_list	*it;

	it = new->target;
	while (it->next && it->next->index == (it->index - 1))
	{
		new->pa += 1;
		it = it->next;
	}
	first->prev->next = first;
}

static t_moves	*get_best_insert(t_info *info, t_list *first)
{
	t_list	*it;
	t_moves	*new;
	t_moves	test;

	new = (t_moves *)malloc(sizeof(t_moves));
	if (!new)
		return (NULL);
	new->target = NULL;
	it = first;
	while (it)
	{
		first->prev->next = first;	
		reinitmove(&test, it, getdist(info->begin_b, info->size_b, it));
		first->prev->next = NULL;
		optrot(info, &test, get_ins_pos(info, &test), test.dist);
		test.pa += 1;
		tot_nb_moves(&test);
		if (new->target == NULL
			|| test.nb_instructions < new->nb_instructions)
			*new = test;
		while (it->next && it->next->index == (it->index - 1))
			it = it->next;
		it = it->next;
	}
	return (nb_pa(new, first), new);
}

t_instructions	*ft_insertbtoa(t_info *info, t_instructions *instructions)
{
	t_list		*first;
	t_moves		*new;
	t_instructions	*new_inst;

	while (info->size_b != 0)
	{
		first = info->begin_b;
		while (first->prev->index == (first->index + 1))
			first = first->prev;
		new = get_best_insert(info, first);
		if (!new)
			return (free_instructions(instructions), NULL);
		execute_actions(info, new, 0);
		new_inst = add_instruction(instructions, new);
		if (!new_inst)
			return (free_instructions(instructions), free(new), NULL);
		instructions = new_inst;
	}
	return (instructions);
}
