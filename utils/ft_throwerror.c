/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throwerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:03:54 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/18 11:55:58 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_throwerror(t_info *info)
{
	ft_freelst(info->begin_a);
	ft_freelst(info->begin_b);
	write(2, WRONG_NUMBER, WRONG_NUMBER_SIZE);
	exit(1);
}
