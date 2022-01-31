/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:35:54 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/31 16:47:23 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_info(t_info **info)
{
	int	i;

	i = 0;
	while (info[i])
	{
		free_list(info[i]->begin_a);
		free_list(info[i]->begin_b);
		free(info[i]);
		i++;
	}
	free(info);
}

static void	init_info(t_info *info, int size)
{
	info->begin_a = NULL;
	info->last_a = NULL;
	info->min = NULL;
	info->maxsort = NULL;
	info->size_a = size;
	info->unordered = 0;
	info->begin_b = NULL;
	info->last_b = NULL;
	info->size_b = 0;
	info->min_b = NULL;
	info->lst_sz = size;
}

static int	cpy_info(t_info *dst, t_info *src)
{
	t_list	*current;
	t_list	*new;

	dst->unordered = src->unordered;
	src->begin_a->prev = NULL;
	current = src->last_a;
	while (current)
	{
		new = lst_addfront(dst->begin_a, current);
		if (!new)
			return (1);
		dst->begin_a = new;
		if (current == src->last_a)
			dst->last_a = dst->begin_a;
		if (current == src->min)
			dst->min = dst->begin_a;
		if (current == src->maxsort)
			dst->maxsort = dst->begin_a;
		current = current->prev;
	}
	dst->begin_a->prev = dst->last_a;
	dst->last_a->next = dst->begin_a;
	src->begin_a->prev = src->last_a;
	return (0);
}

static int	create_first_info(t_info **info, int ac, char **av)
{
	while (ac-- > 1)
	{
		if (lstaddnbr(info[0], av[ac]))
			return (1);
	}
	find_index(info[0]);
	info[0]->begin_a->prev = info[0]->last_a;
	info[0]->last_a->next = info[0]->begin_a;
	find_wrong_pos(info[0]);
	find_max_sorted(info[0]);
	return (0);
}

t_info	**create_tab(int ac, char **av)
{
	int		i;
	t_info	**info;

	info = (t_info **)malloc(sizeof(t_info *) * 5);
	if (!info)
		return (NULL);
	info[4] = NULL;
	i = -1;
	while (++i < 4)
	{
		info[i] = (t_info *)malloc(sizeof(t_info));
		if (!info[i])
			return (free_info(info), NULL);
		init_info(info[i], (ac - 1));
	}
	if (create_first_info(info, ac, av))
		return (free_info(info), NULL);
	if (info[0]->unordered == 0)
		return (info);
	if (cpy_info(info[1], info[0]) || cpy_info(info[2], info[0])
		|| cpy_info(info[3], info[0]))
		return (free_info(info), NULL);
	return (keep_min_only(info[2]), keep_min_only(info[3]), info);
}
