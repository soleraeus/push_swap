/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bringtopos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:40:46 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/17 12:27:11 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bringtofront(t_info *info, int dist, char stack)
{
	while (dist < 0)
	{
		if 	(stack == 'a')
			ft_reverserotateone(&info->begin_a, &info->last_a);
		else
			ft_reverserotateone(&info->begin_b, &info->last_b);
		ft_print_instruction("rr", stack);
		dist++;
	}
	while (dist > 0)
	{
		if 	(stack == 'a')
			ft_rotateone(&info->begin_a, &info->last_a);
		else
			ft_rotateone(&info->begin_b, &info->last_b);
		ft_print_instruction("r", stack);
		dist--;
	}
}
