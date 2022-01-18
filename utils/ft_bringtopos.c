/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bringtopos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:40:46 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/18 12:48:51 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bringtofront(t_moves *possibility, char stack)
{
	int	dist;

	dist = possibility->dist;
	while (dist < 0)
	{
		if 	(stack == 'a')
			possibility->rra += 1;
		else
			possibility->rrb += 1;
		dist++;
	}
	while (dist > 0)
	{
		if 	(stack == 'a')
			possibility->ra += 1;
		else
			possibility->rb += 1;
		dist--;
	}
}
