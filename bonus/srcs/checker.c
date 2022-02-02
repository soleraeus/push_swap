/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:34:19 by bdetune           #+#    #+#             */
/*   Updated: 2022/02/02 20:24:19 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	throw_error(void)
{
	write(2, "Error\n", 6);
}

static int	is_sorted(t_info *info)
{
	t_list	*current;

	if (!info->begin_a || !(info->begin_a->index == 0) || !info->last_a
		|| !(info->last_a->index == (info->lst_sz - 1)) || info->size_b)
		return (free_info(info), write(1, "KO\n", 3), 0);
	if (info->size_a == 1)
		return (free_info(info), write(1, "OK\n", 3), 1);
	info->last_a->next = NULL;
	current = info->begin_a->next;
	while (current)
	{
		if (current->prev->index != (current->index - 1))
			return (free_info(info), write(1, "KO\n", 3), 0);
		current = current->next;
	}
	return (free_info(info), write(1, "OK\n", 3), 1);
}

int	main(int ac, char **av)
{
	t_inst	*inst_lst;
	char	*inst;
	t_info	*info;

	if (ac == 1)
		return (0);
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (1);
	if (create_info(info, ac, av))
		return (free_info(info), 1);
	inst_lst = NULL;
	inst = get_next_line(0);
	while (inst)
	{
		inst_lst = add_inst(inst_lst, inst);
		if (!inst_lst)
			return (free_info(info), 1);
		inst = get_next_line(0);
	}
	if (execute_inst(info, inst_lst))
		return (free_info(info), free_inst(inst_lst), 1);
	is_sorted(info);
	return (0);
}
