/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:26:45 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/10 20:27:10 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_list	*numbers_a;
	t_list	*current;

	if (ac == 1)
		ft_throwerror(&numbers_a);
	numbers_a = NULL;
	while (ac-- > 1)
		ft_lstaddnbr(&numbers_a, av[ac]);
	current = numbers_a;
	while(current)
	{
		printf("%d\n", current->nb);
		current = current->next;
	}
	return (1);
}
