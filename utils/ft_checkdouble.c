/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:38:03 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/11 12:42:12 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checkdouble(t_list **numbers, int nb)
{
	t_list	*current;

	current = *numbers;
	while (current)
	{
		if (current->nb == nb)
			ft_throwerror(numbers);
		current = current->next;
	}
}
