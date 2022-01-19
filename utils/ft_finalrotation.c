/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finalrotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:35:10 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/19 12:10:12 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_finalrotation(t_info *info)
{
	int		iteration;
	t_list	*current;

	while (info->begin_a != info->min)
	{
		iteration = 0;
		current = info->begin_a;
		while (current != info->min)
		{
			current = current->next;
			iteration++;
		}
		if (iteration > info->size_a / 2)
		{
			write(1, "rra\n", 4);
			ft_reverserotateone(&info->begin_a, &info->last_a);
		}
		else
		{
			write(1, "ra\n", 3);
			ft_rotateone(&info->begin_a, &info->last_a);
		}
	}
}
