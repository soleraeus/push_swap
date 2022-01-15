/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:38:10 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/15 15:40:33 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findnextvalid(t_list *begin)
{
	t_list	*current;

	current = begin;
	while (current->streak == -1)
		current = current->next;
	return (current->nb);
}

int	ft_findprevvalid(t_list *begin)
{
	t_list	*current;

	current = begin;
	while (current->streak == -1)
		current = current->prev;
	return (current->nb);
}
