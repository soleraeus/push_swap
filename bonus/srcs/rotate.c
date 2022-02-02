/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:39:19 by bdetune           #+#    #+#             */
/*   Updated: 2022/02/02 19:25:50 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rot_one(t_list **begin, t_list **last)
{
	if (!begin || !*begin || !last || !*last)
		return ;
	*last = *begin;
	*begin = (*begin)->next;
}

void	rot_both(t_info *info)
{
	rot_one(&info->begin_a, &info->last_a);
	rot_one(&info->begin_b, &info->last_b);
}

void	rev_rot_one(t_list **begin, t_list **last)
{
	if (!begin || !*begin || !last || !*last)
		return ;
	*begin = *last;
	*last = (*last)->prev;
}

void	rev_rot_both(t_info *info)
{
	rev_rot_one(&info->begin_a, &info->last_a);
	rev_rot_one(&info->begin_b, &info->last_b);
}
