/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:37:24 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/11 13:03:56 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static t_list	*ft_lstnew(int nb)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->nb = nb;
	return (new);
}

void	ft_lstaddnbr(t_list **numbers, char *av)
{
	long long	nb;
	t_list		*new;
	
	if (ft_checknb(av))
		ft_throwerror(numbers);
	nb = ft_atoll(av);
	if (nb > INT_MAX || nb < INT_MIN)
		ft_throwerror(numbers);
	ft_checkdouble(numbers, nb);
	new = ft_lstnew((int)nb);
	if (!new)
		ft_throwerror(numbers);
	new->next = *numbers;
	*numbers = new;
}
