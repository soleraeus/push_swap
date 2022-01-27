/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finalrotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:35:10 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/27 14:33:33 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instructions	*ft_finalrotation(t_info *info, t_instructions *instructions)
{
	t_moves	*new;

	new = add_possibility(info->min, getdist(info->begin_a, info->size_a, info->min));
	ft_bringtofront(info, new, 'a');
	tot_nb_moves(new);
	simulate_actions(info, new);
	instructions = add_instruction(instructions, new);
	return (instructions);
}
