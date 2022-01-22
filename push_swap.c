/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:26:45 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/22 05:59:29 by bdetune          ###   ########.fr       */
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

void	print_possibility(t_moves *possibility)
{
	printf("nb: %d, nb instructions: %d,  ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d, sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", \
			possibility->nb, possibility->nb_instructions, possibility->ra, possibility->rb, possibility->rr, possibility->rra, possibility->rrb, possibility->rrr, possibility->sa, possibility->sb, possibility->ss, possibility->pa, possibility->pb);
}

int	tot_nb_moves(t_moves *possibility)
{
	if (possibility->nb_instructions)
		return (possibility->nb_instructions);
	possibility->nb_instructions = \
			possibility->ra + possibility->rb + possibility->rr \
			+ possibility->rra + possibility->rrb + possibility->rrr \
			+ possibility->sa + possibility->sb + possibility->ss \
			+ possibility->pa + possibility->pb;
	return (possibility->nb_instructions);
}

void	ft_pushorswap(t_info *info, t_moves *possibility)
{
	t_moves	posswapnext;

	posswapnext = *possibility;
	if (canswapnext(info, possibility->target))
	{
		ft_bringtofront(info, &posswapnext, 'a');
		posswapnext.sa += 1;
	}
	if (canswapprev(info, possibility->target))
	{
		possibility->dist -= 1;
		ft_bringtofront(info, possibility, 'a');
		possibility->sa += 1;
		if (posswapnext.sa == 1 && tot_nb_moves(&posswapnext) < tot_nb_moves(possibility))
			*possibility = posswapnext;
	}
	if (!possibility->sa)
		ft_pushinorder(info, possibility);
	tot_nb_moves(possibility);
}

void	find_least_nb_moves(t_info *info, t_moves *move)
{
	t_list	*lower;
	t_list	*upper;
	t_moves	upper_version;;

	lower = NULL;
	upper = NULL;
	upper_version = *move;
	find_insert_pos_a(info, move, &lower, &upper);
	if (upper)
	{
		optimize_rotations(info, &upper_version, getdist(info->begin_a, info->size_a, upper), upper_version.dist);
		upper_version.pa = 1;
		tot_nb_moves(&upper_version);
		upper_version.pa = upper_version.size_block;
	}
	if (lower)
	{
		optimize_rotations(info, move, getdist(info->begin_a, info->size_a, lower), move->dist);
		move->pa = 1;
		tot_nb_moves(move);
		move->pa = move->size_block;
	}
	if (upper && lower)
	{
		if (upper_version.nb_instructions < move->nb_instructions)
			*move = upper_version;
	}
	else if (upper)
		*move = upper_version;
	else if (!lower)
		move->target = NULL;
}

t_list	*can_push_back(t_info *info, t_moves *move)
{
	t_list	*current;

	if (info->maxsorted == info->min)
	{
		if (move->target->index == (info->tot_size - 1))
			return (info->min);
		return (NULL);
	}
	current = info->maxsorted;
	while (current->prev->index == (current->index - 1))
		current = current->prev;
	if (move->target->index == (current->index - 1))
		return (current);
	return (NULL);
}

t_moves	find_best_move_insert(t_info *info)
{
	int		i;
	t_list	*loc_a;
	t_moves	ret;
	t_moves	**tab;
	
	tab = NULL;
	loc_a = NULL;
	tab = ft_findblocks(info);
	ret.target = NULL;
	i = 0;
	while (tab[i])
	{
		loc_a = can_push_back(info, tab[i]);
		if (loc_a)
		{
			ret = *(tab[i]);
			break ;
		}
		i++;
	}
	if (ret.target)
	{
//		printf("found one\n");
		optimize_rotations(info, &ret, getdist(info->begin_a, info->size_a, loc_a), ret.dist);
		ret.pa = 1;
		tot_nb_moves(&ret);
		ret.pa = ret.size_block;
	}		
	return (free_possibilities(tab), ret);
}

t_moves	find_best_move_remove(t_info *info)
{
	int	i;
	t_moves	ret;
	t_moves	*min;
	t_moves	**tab;
	
	min = NULL;
	tab = NULL;
	tab = ft_findtargets(info);
	i = 0;
	while (tab[i])
	{
		ft_pushorswap(info, tab[i]);
		if (i == 0)
			min = tab[i];
		else
		{
			if (tab[i]->nb_instructions < min->nb_instructions)
				min = tab[i];
			else if (tab[i]->nb_instructions == min->nb_instructions
				&& tab[i]->nb > min->nb)
				min = tab[i];
		}
		i++;
	}
	ret = *min;
	return (free_possibilities(tab), ret);
}

void	ft_sortlist(t_info *info)
{
	t_moves possibility_remove;
	t_moves	possibility_insert;

	while (info->unordered != 0)
	{
		possibility_insert.target = NULL;
//		ft_printlist(&info->begin_a, &info->last_a, 'A');
//		ft_printlist(&info->begin_b, &info->last_b, 'B');
		possibility_remove = find_best_move_remove(info);
		if (info->size_b)
		{
			possibility_insert = find_best_move_insert(info);
			if (possibility_insert.target != NULL && possibility_insert.nb_instructions < possibility_remove.nb_instructions)
			{
				info->maxsorted = possibility_insert.block_end;
				execute_actions(info, &possibility_insert);
			}
			else
			{
				execute_actions(info, &possibility_remove);
				info->unordered -= 1;
			}
		}
		else
		{
			execute_actions(info, &possibility_remove);
			info->unordered -= 1;
		}
	}
//	ft_printlist(&info->begin_a, &info->last_a, 'A');
//	ft_printlist(&info->begin_b, &info->last_b, 'B');
	if (info->size_b != 0)
		ft_insertbtoa(info);
	ft_finalrotation(info);
//	ft_printlist(&info->begin_a, &info->last_a, 'A');
//	ft_printlist(&info->begin_b, &info->last_b, 'B');
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
	findindex(&info);
	findmaxsorted(&info);
	info.begin_a->prev = info.last_a;
	info.last_a->next = info.begin_a;
	ft_findwrongpos(&info);
	if (info.unordered == 0)
		return (ft_finalrotation(&info), ft_freelst(info.begin_a), 0);
//	ft_printlist(&info.begin_a, &info.last_a, 'A');
//	printf("%d\n", info.min->streak);
	ft_sortlist(&info);
	return (0);
}
