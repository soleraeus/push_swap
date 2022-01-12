/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finalrotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:35:10 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/12 12:49:40 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_finalrotation(t_list **numbers_a, int size)
{
	int		iteration;
	t_list	*current;

	while ((*numbers_a)->index != 0)
	{
		iteration = 0;
		current = *numbers_a;
		while (current->index != 0)
		{
			current = current->next;
			iteration++;
		}
		if (iteration > size / 2)
		{
			write(1, "rra\n", 4);
			ft_reverserotateone(numbers_a);
		}
		else
		{
			write(1, "ra\n", 3);
			ft_rotateone(numbers_a);
		}
	}
}
