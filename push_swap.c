/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:26:45 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/22 08:29:56 by bdetune          ###   ########.fr       */
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

t_moves	*find_best_move_insert(t_info *info)
{
	int		i;
	t_list	*loc_a;
	t_moves	*ret;
	t_moves	**tab;
	
	tab = NULL;
	loc_a = NULL;
	tab = ft_findblocks(info);
	ret = (t_moves *)malloc(sizeof(t_moves));
	ret->target = NULL;
	i = 0;
	while (tab[i])
	{
		loc_a = can_push_back(info, tab[i]);
		if (loc_a)
		{
			*ret = *(tab[i]);
			break ;
		}
		i++;
	}
	if (ret->target)
	{
		optimize_rotations(info, ret, getdist(info->begin_a, info->size_a, loc_a), ret->dist);
		ret->pa = 1;
		tot_nb_moves(ret);
		ret->pa = ret->size_block;
	}		
	return (free_possibilities(tab), ret);
}

t_moves	*find_best_move_remove(t_info *info)
{
	int	i;
	t_moves	*ret;
	t_moves	**tab;
	
	tab = NULL;
	ret = (t_moves *)malloc(sizeof(t_moves));
	tab = ft_findtargets(info);
	i = 0;
	while (tab[i])
	{
		ft_pushorswap(info, tab[i]);
		if (i == 0)
			*ret = *(tab[i]);
		else
		{
			if (tab[i]->nb_instructions < ret->nb_instructions)
				*ret = *(tab[i]);
			else if (tab[i]->nb_instructions == ret->nb_instructions
				&& tab[i]->nb > ret->nb)
				*ret = *(tab[i]);
		}
		i++;
	}
	return (free_possibilities(tab), ret);
}

t_instructions	*ft_sortlist_insert(t_info *info)
{
	t_instructions	*instructions;
	t_moves 		*possibility_remove;
	t_moves			*possibility_insert;

	instructions = NULL;
	while (info->unordered != 0)
	{
		possibility_insert = NULL;
		possibility_remove = find_best_move_remove(info);
		if (info->size_b)
		{
			possibility_insert = find_best_move_insert(info);
			if (possibility_insert->target != NULL && possibility_insert->nb_instructions < possibility_remove->nb_instructions)
			{
				info->maxsorted = possibility_insert->block_end;
				execute_actions(info, possibility_insert);
				instructions = add_instruction(instructions, possibility_insert);
				free(possibility_remove);
			}
			else
			{
				execute_actions(info, possibility_remove);
				instructions = add_instruction(instructions, possibility_remove);
				free(possibility_insert);
				info->unordered -= 1;
			}
		}
		else
		{
			execute_actions(info, possibility_remove);
			instructions = add_instruction(instructions, possibility_remove);
			info->unordered -= 1;
		}
	}
	if (info->size_b != 0)
		instructions = ft_insertbtoa(info, instructions);
	instructions = ft_finalrotation(info, instructions);
	ft_freelst(info->begin_a);
	return (instructions);
}

int	main(int ac, char **av)
{
//	int				i;
	t_info			*info;
	t_instructions	*min;
//	t_instructions	*current;

	info = (t_info *)malloc(sizeof(t_info) * 4);
	if (!info)
		return (1);
	ft_initinfo(&(info[0]), (ac - 1));
	if (ac == 1)
		return (0);
	while (ac-- > 1)
		ft_lstaddnbr(&(info[0]), av[ac]);
	if (info[0].size_a == 1)
		return (free(info[0].begin_a), 0);
	findindex(&(info[0]));
	findmaxsorted(&(info[0]));
	info[0].begin_a->prev = info[0].last_a;
	info[0].last_a->next = info[0].begin_a;
	ft_findwrongpos(&(info[0]));
	if (info[0].unordered == 0)
		return (ft_finalrotation(&(info[0]), NULL), ft_freelst(info[0].begin_a), 0);
//	ft_printlist(&info.begin_a, &info.last_a, 'A');
//	printf("%d\n", info.min->streak);
	min = ft_sortlist_insert(&(info[0]));
	return (0);
}
