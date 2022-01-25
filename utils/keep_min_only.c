/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_min_only.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:43:30 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/25 17:43:07 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	keep_min_only(t_info *info)
{
	t_list	*current;

	current = info->min->next;
	while (current != info->min)
	{
		current->streak = -1;
		current = current->next;
	}
	info->unordered = info->tot_size - 1;
}
