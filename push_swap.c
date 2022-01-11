/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:26:45 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/11 14:13:07 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_list	*numbers_a;
	t_list	*numbers_b;
	t_list	*current;

	if (ac == 1)
		ft_throwerror(&numbers_a);
	numbers_a = NULL;
	numbers_b = NULL;
	while (ac-- > 1)
		ft_lstaddnbr(&numbers_a, av[ac]);
	ft_swapone(&numbers_a);
	ft_push(&numbers_b, &numbers_a);
	ft_push(&numbers_b, &numbers_a);
	ft_push(&numbers_b, &numbers_a);
	ft_rotateboth(&numbers_a, &numbers_b);
	ft_reverserotateboth(&numbers_a, &numbers_b);
	ft_swapone(&numbers_a);
	ft_push(&numbers_a, &numbers_b);
	ft_push(&numbers_a, &numbers_b);
	ft_push(&numbers_a, &numbers_b);
	write(1, "Stack A\n", 8);
	current = numbers_a;
	while(current)
	{
		printf("%d\n", current->nb);
		current = current->next;
	}
	write(1, "Stack B\n", 8);
	current = numbers_b;
	while(current)
	{
		printf("%d\n", current->nb);
		current = current->next;
	}
	return (1);
}
