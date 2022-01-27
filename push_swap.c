/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:26:45 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/27 19:29:26 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


void	ft_printlist(t_list **begin, t_list **last, char c)
{
	t_list	*current;

	(void)c;
	current = *begin;
	write(1, "Stack ", 6);
	write(1, &c, 1);
	write(1, "\n", 1);
	while (current && current != *last)
	{
		printf("index: %d - %d - streak: %d\n", current->index, current->nb, current->streak);
		current = current->next;
	}
	if (*last)
		printf("index: %d - %d - streak: %d\n", current->index, current->nb, current->streak);
	return ;
}

int	tot_nb_moves(t_moves *possibility)
{
	possibility->nb_instructions = \
			possibility->ra + possibility->rb + possibility->rr \
			+ possibility->rra + possibility->rrb + possibility->rrr \
			+ possibility->sa + possibility->sb + possibility->ss \
			+ possibility->pa + possibility->pb;
	return (possibility->nb_instructions);
}

int	main(int ac, char **av)
{
	t_info			**info;
	t_instructions	*begin;

	if (ac == 1)
		return (0);
	info = create_tab(ac, av);
	if (!info)
		return (1);
	if (info[0]->unordered == 0)
	{
		min = ft_finalrotation(info[0], NULL);
		execute_actions(NULL, min, 1);
		free_info(info);
		return (free_info(info), free0);
	}
	begin = sort(info);
	if (!begin)
		return (free_info(info), 1)
	print_instructions(begin);
	free_info(info);
	return (0);
}
