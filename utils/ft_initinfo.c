/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:51:37 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/17 11:38:25 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initinfo(t_info *info, int size)
{
	info->begin_a = NULL;
	info->last_a = NULL;
	info->min = NULL;
	info->size_a = size;
	info->unordered = 0;
	info->begin_b = NULL;
	info->last_b = NULL;
	info->size_b = 0;
	info->min_b = NULL;
}
