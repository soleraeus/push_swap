/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:34:05 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/17 14:25:15 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotateone(t_list **begin, t_list **last)
{
	*last = *begin;
	*begin = (*begin)->next;
}

void	ft_rotateboth(t_info *info)
{
	ft_rotateone(&info->begin_a, &info->last_a);
	ft_rotateone(&info->begin_b, &info->last_b);
	write(1, "rr\n", 3);
}

void	ft_reverserotateone(t_list **begin, t_list **last)
{
	*begin = *last;
	*last = (*last)->prev;
}

void	ft_reverserotateboth(t_info *info)
{
	ft_reverserotateone(&info->begin_a, &info->last_a);
	ft_reverserotateone(&info->begin_b, &info->last_b);
	ft_print_instruction("rr", 'r');
}
