/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finalrotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:35:10 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/22 08:31:55 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instructions	*ft_finalrotation(t_info *info, t_instructions *instructions)
{
	t_moves	*new;

	new = (t_moves *)malloc(sizeof(t_moves));
	new->dist = getdist(info->begin_a, info->size_a, info->min);
	if (!new->dist)
		return (free(new), instructions);
	new->target = info->min;
	ft_bringtofront(info, new, 'a');
	execute_actions(info, new);
	instructions = add_instruction(instructions, new);
	return (instructions);
}
