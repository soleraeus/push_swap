/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:26:45 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/19 12:11:37 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


void	ft_printlist(t_list **begin, t_list **last, char c)
{
	t_list	*current;

//	(void)c;
	current = *begin;
	write(1, "Stack ", 6);
	write(1, &c, 1);
	write(1, "\n", 1);
	while (current && current != *last)
	{
		printf("%d\n", current->nb);
		current = current->next;
	}
	if (*last)
		printf("%d\n", current->nb);
	return ;
}

void	print_possibility(t_moves *possibility)
{
	printf("nb: %d, ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d, sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", \
			possibility->nb, possibility->ra, possibility->rb, possibility->rr, possibility->rra, possibility->rrb, possibility->rrr, possibility->sa, possibility->sb, possibility->ss, possibility->pa, possibility->pb);
}

void	tot_nb_moves(t_moves *possibility)
{
	possibility->nb_instructions = \
			possibility->ra + possibility->rb + possibility->rr \
			+ possibility->rra + possibility->rrb + possibility->rrr \
			+ possibility->sa + possibility->sb + possibility->ss \
			+ possibility->pa + possibility->pb;
}

void	ft_pushorswap(t_info *info, t_moves *possibility)
{
	if (canswapnext(info, possibility->target))
	{
		ft_bringtofront(possibility, 'a');
		possibility->sa += 1;
		return ;
	}
	if (canswapprev(info, possibility->target))
	{
		possibility->dist -= 1;
		ft_bringtofront(possibility, 'a');
		possibility->sa += 1;
		return ;
	}
	ft_pushinorder(info, possibility);
}

void	find_best_move(t_info *info)
{
	int		i;
	t_moves	*min;
	t_moves	**tab;
	
	min = NULL;
	tab = NULL;
	tab = ft_findtargets(info);
	i = 0;
	while (tab[i])
	{
		ft_pushorswap(info, tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
//		print_possibility(tab[i]);
		tot_nb_moves(tab[i]);
		if (!min)
			min = tab[i];
		else
		{
			if (tab[i]->nb_instructions < min->nb_instructions)
				min = tab[i];
			else if (tab[i]->nb_instructions == min->nb_instructions
				&& tab[i]->nb < min->nb)
				min = tab[i];
		}
		i++;
	}
//	printf("Used :\n");
//	print_possibility(min);
	execute_actions(info, min);
	min->target->streak = 1;
	info->unordered -= 1;
	free_possibilities(tab);
}

void	ft_sortlist(t_info *info)
{
	while (info->unordered != 0)
	{
//		ft_printlist(&info->begin_a, &info->last_a, 'A');
//		ft_printlist(&info->begin_b, &info->last_b, 'B');
		if (info->size_a == 3)
		{
			ft_swapone(&info->begin_a);
			write(1, "sa\n", 3);
			info->unordered = 0;
			break ;
		}
		find_best_move(info);
	}
//	ft_printlist(&info->begin_a, &info->last_a, 'A');
//	ft_printlist(&info->begin_b, &info->last_b, 'B');
	if (info->size_b != 0)
		ft_insertbtoa(info);
	ft_finalrotation(info);
//	ft_printlist(&info->begin_a, &info->last_a, 'A');
//	ft_printlist(&info->begin_b, &info->last_b, 'B');
//	ft_freelst(info->begin_a);

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
//	printf("%d\n", info.min->streak);
	ft_sortlist(&info);
	return (0);
}
