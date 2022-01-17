/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertbtoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:13:34 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/17 11:56:20 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findinsertpos(t_info *info, int nb)
{
	int		dist;
	t_list	*current_begin;
	t_list	*current_last;

	if (info->last_a->nb < nb && (info->begin_a->nb > nb 
			|| info->begin_a->nb == info->min->nb))
		return (0);
	dist = 1;
	current_begin = info->begin_a->next;
	current_last = info->last_a;
	while (1)
	{
		if (current_begin->prev->nb < nb && (current_begin->nb > nb
				|| current_begin->nb == info->min->nb))
			return (dist);
		if (current_last->prev->nb < nb && (current_last->nb > nb
				|| current_last->nb == info->min->nb))
			return (-dist);
		current_begin = current_begin->next;
		current_last = current_last->prev;
		dist++;
	}

}

void	ft_insertbtoa(t_info *info)
{
	int		dist;
	t_list	*target;

	while (info->size_b != 0)
	{
		target = info->begin_b;
		dist = ft_findinsertpos(info, target->nb);
		ft_bringtofront(info, dist, 'a');
		ft_print_instruction("p", 'a');
		ft_pusha(info);
	}
}
