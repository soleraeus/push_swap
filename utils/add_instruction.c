/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 07:39:23 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/22 08:28:39 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instructions	*add_instruction(t_instructions *instructions, t_moves *move)
{
	t_instructions	*new;

	new = (t_instructions *)malloc(sizeof(t_instructions));
	new->prev = NULL;
	new->moves = move;
	if (move->pa)
		new->tot_nb_instructions = move->nb_instructions - 1 + move->pa;
	else
		new->tot_nb_instructions = move->nb_instructions;
	if (!instructions)
		new->first = new;
	else
	{
		new->first = instructions->first;
		new->tot_nb_instructions += instructions->tot_nb_instructions;
		instructions->prev = new;
	}
	return (new);
}
