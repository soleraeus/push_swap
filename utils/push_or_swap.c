/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_or_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:00:32 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/31 17:04:23 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushinorder(t_info *info, t_moves *possibility)
{
	int		nb;
	int		dist_b;
	t_list	*it;

	nb = possibility->nb;
	if (info->size_b == 0 || info->size_b == 1)
	{
		ft_bringtofront(info, possibility, 'a');
		possibility->pb += 1;
		return ;
	}
	dist_b = 0;
	it = info->begin_b;
	while (1)
	{
		if ((it->nb < nb && (it->prev->nb > nb || it->prev == info->min_b))
			|| (nb < info->min_b->nb && it->prev == info->min_b))
			break ;
		dist_b++;
		it = it->next;
	}
	optrot(info, possibility, possibility->dist, dist_b);
	possibility->pb += 1;
}

static int	canswapnext(t_info *info, t_list *unordered)
{
	if (info->unordered == (info->size_a - 1))
		return (0);
	if (unordered->next->streak != -1
		&& unordered->next->index == (unordered->index - 1))
		return (1);
	return (0);
}

static int	canswapprev(t_info *info, t_list *unordered)
{
	if (info->unordered == (info->size_a - 1))
		return (0);
	if (unordered->index == (info->lst_sz - 1))
	{
		if (unordered->prev->index == 0)
			return (1);
		return (0);
	}
	if (unordered->prev->streak != -1
		&& unordered->prev->index == (unordered->index + 1))
		return (1);
	return (0);
}

void	push_or_swap(t_info *info, t_moves *mv)
{
	t_moves	pos_sa_nxt;

	pos_sa_nxt = *mv;
	if (canswapnext(info, mv->target))
	{
		ft_bringtofront(info, &pos_sa_nxt, 'a');
		pos_sa_nxt.sa += 1;
	}
	if (canswapprev(info, mv->target))
	{
		mv->dist -= 1;
		ft_bringtofront(info, mv, 'a');
		mv->sa += 1;
		if (tot_nb_moves(&pos_sa_nxt) < tot_nb_moves(mv) && pos_sa_nxt.sa)
			*mv = pos_sa_nxt;
		return ;
	}
	if (pos_sa_nxt.sa)
	{
		*mv = pos_sa_nxt;
		tot_nb_moves(mv);
		return ;
	}
	ft_pushinorder(info, mv);
	tot_nb_moves(mv);
}
