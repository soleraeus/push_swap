/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finalrotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:35:10 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/27 20:21:19 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instructions	*ft_finalrotation(t_info *info, t_instructions *instructions)
{
	t_moves			*new;
	t_instructions	*new_instruct;

	new = add_move(info->min, getdist(info->begin_a, info->size_a, info->min));
	if (!new)
		return (free_instructions(instructions), NULL);
	ft_bringtofront(info, new, 'a');
	tot_nb_moves(new);
	execute_actions(info, new, 0);
	new_instruct = add_instruction(instructions, new);
	if (!new_instruct)
		return (free(new), free_instructions(instructions), NULL);
	instructions = new_instruct;
	return (instructions);
}
