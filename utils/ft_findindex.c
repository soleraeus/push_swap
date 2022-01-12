/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findindex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:53:44 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/12 12:23:56 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_findindex(t_list **numbers_a, int size)
{
	int		maxval;
	t_list	*current;
	t_list	*maxptr;

	while (size-- > 0)
	{
		current = *numbers_a;
		maxptr = NULL;
		maxval = INT_MIN;
		while (current)
		{
			if (current->index == -1 && current->nb >= maxval)
			{
				maxptr = current;
				maxval = current->nb;
			}
			current = current->next;
		}
		maxptr->index = size;
	}
}
