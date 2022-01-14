/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:38:03 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/14 16:29:40 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checkdouble(t_info *info, int nb)
{
	t_list	*current;

	current = info->begin_a;
	while (current)
	{
		if (current->nb == nb)
			ft_throwerror(info);
		current = current->next;
	}
}
