/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:34:05 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/11 14:11:12 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotateone(t_list **begin)
{
	t_list	*current;

	if (!begin || !*begin)
		return ;
	current = *begin;
	if (!current)
		return ;
	while (current->next)
		current = current->next;
	current->next = *begin;
	*begin = (*begin)->next;
	current->next->next = NULL;
}

void	ft_rotateboth(t_list **numbers_a, t_list **numbers_b)
{
	ft_rotateone(numbers_a);
	ft_rotateone(numbers_b);
}

void	ft_reverserotateone(t_list **begin)
{
	t_list	*prev;
	t_list	*current;

	if (!begin || !*begin)
		return ;
	prev = *begin;
	if (!prev->next)
		return ;
	current = prev->next;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	current->next = *begin;
	*begin = current;
	prev->next = NULL;
}

void	ft_reverserotateboth(t_list **numbers_a, t_list **numbers_b)
{
	ft_reverserotateone(numbers_a);
	ft_reverserotateone(numbers_b);
}
