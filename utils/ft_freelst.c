/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:06:00 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/15 16:31:02 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freelst(t_list *begin)
{
	t_list	*next;

	if (begin->prev)
		begin->prev->next = NULL;
	while (begin)
	{
		next = begin->next;
		free(begin);
		begin = next;
	}
}
