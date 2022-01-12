/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushandswap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:33:41 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/12 12:23:21 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swapone(t_list **begin)
{
	int	swapnb;
	int	swapindex;

	if (!begin || !*begin || !(*begin)->next)
		return ;
	swapnb = (*begin)->nb;
	swapindex = (*begin)->index;
	(*begin)->nb = (*begin)->next->nb;
	(*begin)->index = (*begin)->next->index;
	(*begin)->next->nb = swapnb;
	(*begin)->next->index = swapindex;
}

void	ft_swapboth(t_list **numbers_a, t_list **numbers_b)
{
	ft_swapone(numbers_a);
	ft_swapone(numbers_b);
}

void	ft_push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}
