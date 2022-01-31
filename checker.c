/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:34:19 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/31 21:12:10 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(t_info **info)
{
	if (!info->begin_a || !info->begin_a->index == 0 || !info->last_a
			|| !info->last_a->index == (info->lst_size - 1))
		return (write(2, "KO\n", 3), 0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (0);
}

int	apply_action(t_info *info, char *inst)
{
	if (ft_strcmp(inst, "sa\n"))
		swap_one(info, 'A');
	else if (ft_strcmp(inst, "sb\n"))
		swap_one(info, 'B');
	else if (ft_strcmp(inst, "ss\n"))
		swap_both(info);
	else if (ft_strcmp(inst, "pa\n"))
		ft_pusha(info);
	else if (ft_strcmp(inst, "pb\n"))
		ft_pushb(info);
	else if (ft_strcmp(inst, "ra\n"))
		ft_rotateone(&info->begin_a, &info->last_a);
	else if (ft_strcmp(inst, "rb\n"))
		ft_rotateone(&info->begin_b, &info->last_b);
	else if (ft_strcmp(inst, "rr\n"))
		ft_rotateboth(info);
	else if (ft_strcmp(inst, "rra\n"))
		ft_reverserotateone(&info->begin_a, &info->last_a);
	else if (ft_strcmp(inst, "rrb\n"))
		ft_reverserotateone(&info->begin_b, &info->last_b);
	else if (ft_strcmp(inst, "rrr\n"))
		ft_reverserotateboth(info);
	else
		return (free(inst), 1);
	return (free(inst), 0);
}

int	main(int ac, char **av)
{
	char	*inst;
	t_info	**info;

	if (ac == 1)
		return (0);
	info = (info **)malloc(sizeof(info *) * 2);
	if (!info)
		return (1);
	info[0] = (info *)malloc(sizeof(info));
	if (!info[0])
		return (free(info), 1);
	info[1] = NULL;
	init_info(info[0], (ac - 1));
	if (create_first_info(info, ac, av))
		return (free_info(info), 1);
	inst = get_next_line(0);
	while (inst)
	{
		if (apply_action(info[0], inst))
			return (throw_error(), free_info(info), 1);
		inst = get_next_line(0);
	}
	return (!is_sorted(info));
}
