/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:06:00 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/10 20:07:49 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freelst(t_list **begin)
{
	t_list	*current;
	t_list	*next;

	current = *begin;
	while(current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
