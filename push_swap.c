/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:26:45 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/15 18:02:18 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


void	ft_printlist(t_list **begin, t_list **last, char c)
{
	t_list	*current;

	(void)c;
	current = *begin;
//	write(1, "Stack ", 6);
//	write(1, &c, 1);
//	write(1, "\n", 1);
	while (current && current != *last)
	{
//		printf("%d\n", current->nb);
		current = current->next;
	}
	if (*last)
//		printf("%d\n", current->nb);
	return ;
}

void	ft_pushorswap(t_info *info)
{
	int		dist;
	t_list	*unordered;
	int		next_valid_val;
	int		prev_valid_val;

	dist = ft_findclosest(info, &unordered);
	info->unordered -= 1;
	if (unordered->next->streak != -1 && unordered->next->nb < unordered->nb)
	{
		next_valid_val = ft_findnextvalid(unordered->next->next);
		if (next_valid_val > unordered->nb || next_valid_val == info->min->nb)
		{
			ft_bringtofront(info, dist, 'a');
			unordered->streak = 1;
			write(1, "sa\n", 3);
			ft_swapone(&info->begin_a);
			return ;
		}
	}
	if (unordered->prev->streak != -1
		&& (unordered->prev->nb > unordered->nb
			|| unordered->prev->nb == info->min->nb))
	{
		prev_valid_val = ft_findprevvalid(unordered->prev->prev);
		if (prev_valid_val < unordered->nb)
		{
			ft_bringtofront(info, (dist - 1), 'a');
			unordered->streak = 1;
			write(1, "sa\n", 3);
			ft_swapone(&info->begin_a);
			return ;
		}
	}
	ft_bringtofront(info, dist, 'a');
	write(1, "pb\n", 3);
	ft_pushb(info);
}

void	ft_sortlist(t_info *info)
{
	while (info->unordered != 0)
	{
		ft_printlist(&info->begin_a, &info->last_a, 'A');
		ft_printlist(&info->begin_b, &info->last_b, 'B');
		if (info->size_a == 3)
		{
			ft_swapone(&info->begin_a);
			write(1, "sa\n", 3);
			info->unordered = 0;
			break ;
		}
		ft_pushorswap(info);
	}
	ft_printlist(&info->begin_a, &info->last_a, 'A');
	ft_printlist(&info->begin_b, &info->last_b, 'B');
	if (info->size_b != 0)
		ft_insertbtoa(info);
	ft_finalrotation(info);
	ft_printlist(&info->begin_a, &info->last_a, 'A');
	ft_printlist(&info->begin_b, &info->last_b, 'B');
	ft_freelst(info->begin_a);
}

int	main(int ac, char **av)
{
	t_info	info;

	ft_initinfo(&info, (ac - 1));
	if (ac == 1)
		return (0);
	while (ac-- > 1)
		ft_lstaddnbr(&info, av[ac]);
	if (info.size_a == 1)
		return (free(info.begin_a), 0);
	info.begin_a->prev = info.last_a;
	info.last_a->next = info.begin_a;
	ft_findwrongpos(&info);
	if (info.unordered == 0)
		return (ft_finalrotation(&info), ft_freelst(info.begin_a), 0);
	printf("%d\n", info.min->streak);
//	ft_sortlist(&info);
	return (0);
}
