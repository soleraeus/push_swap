/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:50:37 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/31 19:10:49 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_moves	*pa_or_pb(t_info *info, t_moves *mv_lst, int insert)
{
	t_moves	*ret;
	t_moves	mv_ins;

	ret = (t_moves *)malloc(sizeof(t_moves));
	if (!ret)
		return (free_mv_lst(mv_lst), NULL);
	*ret = best_mv_rm(info);
	if (insert && info->size_b)
	{
		mv_ins = best_mv_ins(info);
		if (mv_ins.target && mv_ins.nb_op <= ret->nb_op)
		{
			*ret = mv_ins;
			info->unordered += 1;
		}
	}
	execute_actions(info, ret, 0);
	info->unordered -= 1;
	mv_lst = add_mv(mv_lst, ret);
	return (mv_lst);
}

static t_moves	*sortlist(t_info *info, int insert)
{
	t_moves	*mv_lst;

	mv_lst = NULL;
	while (info->unordered != 0)
	{
		mv_lst = pa_or_pb(info, mv_lst, insert);
		if (!mv_lst)
			return (NULL);
	}
	if (info->size_b != 0)
	{
		mv_lst = ft_insertbtoa(info, mv_lst);
		if (!mv_lst)
			return (NULL);
	}
	if (info->begin_a != info->min)
	{
		mv_lst = finalrot(info, mv_lst);
		if (!mv_lst)
			return (NULL);
	}
	return (mv_lst);
}

static t_moves	*keep_min(t_moves *min, t_moves *current)
{
	if (!current)
		return (free_mv_lst(min), NULL);
	if (!min)
		return (current);
	if (current->nb_op < min->nb_op)
	{
		free_mv_lst(min);
		return (current);
	}
	free_mv_lst(current);
	return (min);
}

t_moves	*sort(t_info **info)
{
	int		i;
	t_moves	*min;

	i = -1;
	min = NULL;
	while (++i < 4)
	{
		min = keep_min(min, sortlist(info[i], (i % 2)));
		if (!min)
			return (NULL);
	}
	return (min);
}
