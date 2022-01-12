/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:26:10 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/12 12:33:52 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted(t_list *numbers_a)
{
	t_list	*current;

	current = numbers_a;
	while (current->next)
	{
		if (current->next->index != (current->index + 1)
			&& current->next->index != 0)
			return (0);
		current = current->next;
	}
	return (1);
}
