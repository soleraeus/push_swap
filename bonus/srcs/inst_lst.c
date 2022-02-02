/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:59:09 by bdetune           #+#    #+#             */
/*   Updated: 2022/02/02 19:47:00 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_inst(t_inst *inst_lst)
{
	t_inst	*current;
	t_inst	*prev;

	if (!inst_lst)
		return ;
	current = inst_lst->first;
	while (current)
	{
		prev = current->prev;
		free(current->inst);
		free(current);
		current = current->prev;
	}
}

t_inst	*add_inst(t_inst *inst_lst, char *inst)
{
	t_inst	*new_inst;

	new_inst = (t_inst *)malloc(sizeof(t_inst));
	if (!new_inst)
		return (free(inst), free_inst(inst_lst), NULL);
	new_inst->inst = inst;
	new_inst->prev = NULL;
	if (!inst_lst)
		new_inst->first = new_inst;
	else
	{
		new_inst->first = inst_lst->first;
		inst_lst->prev = new_inst;
	}
	return (new_inst);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1)
		return (s2[0]);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s2[i] - s1[i]);
}

static int	apply_action(t_info *info, char *inst)
{
	if (!ft_strcmp(inst, "sa\n"))
		swap_one(info, 'A');
	else if (!ft_strcmp(inst, "sb\n"))
		swap_one(info, 'B');
	else if (!ft_strcmp(inst, "ss\n"))
		swap_both(info);
	else if (!ft_strcmp(inst, "pa\n"))
		push_a(info);
	else if (!ft_strcmp(inst, "pb\n"))
		push_b(info);
	else if (!ft_strcmp(inst, "ra\n"))
		rot_one(&info->begin_a, &info->last_a);
	else if (!ft_strcmp(inst, "rb\n"))
		rot_one(&info->begin_b, &info->last_b);
	else if (!ft_strcmp(inst, "rr\n"))
		rot_both(info);
	else if (!ft_strcmp(inst, "rra\n"))
		rev_rot_one(&info->begin_a, &info->last_a);
	else if (!ft_strcmp(inst, "rrb\n"))
		rev_rot_one(&info->begin_b, &info->last_b);
	else if (!ft_strcmp(inst, "rrr\n"))
		rev_rot_both(info);
	else
		return (throw_error(), 1);
	return (0);
}

int	execute_inst(t_info *info, t_inst *inst_lst)
{
	t_inst	*current;
	t_inst	*prev;

	if (!inst_lst)
		return (0);
	current = inst_lst->first;
	while (current)
	{
		prev = current->prev;
		if (apply_action(info, current->inst))
			return (1);
		inst_lst->first = prev;
		free(current->inst);
		free(current);
		current = prev;
	}
	return (0);
}
