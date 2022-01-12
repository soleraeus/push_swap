/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:26:45 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/12 12:53:09 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		size;
	t_list	*numbers_a;
	t_list	*numbers_b;
	t_list	*current;

	if (ac == 1)
		ft_throwerror(&numbers_a);
	numbers_a = NULL;
	numbers_b = NULL;
	size = ac - 1;
	while (ac-- > 1)
		ft_lstaddnbr(&numbers_a, av[ac]);
	ft_findindex(&numbers_a, size);
	if (!numbers_b && ft_issorted(numbers_a))
		ft_finalrotation(&numbers_a, size);
	else
	{
		ft_push(&numbers_b, &numbers_a);
		ft_push(&numbers_b, &numbers_a);
	}
	write(1, "Stack A\n", 8);
	current = numbers_a;
	while(current)
	{
		printf("number: %d, index: %d\n", current->nb, current->index);
		current = current->next;
	}
	write(1, "Stack B\n", 8);
	current = numbers_b;
	while(current)
	{
		printf("number: %d, index: %d\n", current->nb, current->index);
		current = current->next;
	}
	return (1);
}
