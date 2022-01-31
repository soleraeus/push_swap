#include "push_swap.h"

int	tot_nb_moves(t_moves *mv)
{
	mv->nb_instructions = mv->ra + mv->rb + mv->rr + mv->rra + mv->rrb + mv->rrr \
			+ mv->sa + mv->sb + mv->ss + mv->pa + mv->pb;
	return (mv->nb_instructions);
}

t_instructions	*finalrot(t_info *info, t_instructions *instructions)
{
	t_moves			*new_mv;
	t_instructions	*new_instruct;

	new_mv = (t_moves *)malloc(sizeof(t_moves));
	if (!new_mv)
		return (free_instructions(instructions), NULL);
	init_mv(new_mv, info->min, getdist(info->begin_a, info->size_a, info->min));
	ft_bringtofront(info, new_mv, 'a');
	tot_nb_moves(new_mv);
	execute_actions(info, new_mv, 0);
	new_instruct = add_instruction(instructions, new_mv);
	if (!new_instruct)
		return (free(new_mv), free_instructions(instructions), NULL);
	instructions = new_instruct;
	return (instructions);
}

t_moves	find_best_move_insert(t_info *info)
{
	int		i;
	t_list	*it;
	t_moves	ret;

	ret.target = NULL;
	info->last_b->next = NULL;
	it = info->begin_b;
	i = 0;
	while (it)
	{
		if (it->index == (info->maxsorted->index - 1)
			|| (info->maxsorted == info->min && it->index == (info->tot_size - 1)))
		{
			init_mv(&ret, it, i);
			break ;
		}
		i++;
		it = it->next;
	}
	info->last_b->next = info->begin_b;
	if (ret.target)
	{
		optrot(info, &ret, getdist(info->begin_a, info->size_a, info->maxsorted), i);
		ret.pa = 1;
		tot_nb_moves(&ret);
		ret.target->prev->next = NULL;
		nb_pa(&ret, ret.target);
	}		
	return (ret);
}


t_moves	find_best_move_remove(t_info *info)
{
	t_moves	ret;
	t_moves	test;
	t_list	*current;

	ret.target = NULL;
	current = info->min->next;;
	while (current != info->min)
	{
		if (current->streak == -1)
		{
			init_mv(&test, current, getdist(info->begin_a, info->size_a, current));
			ft_pushorswap(info, &test);
			if (ret.target == NULL || test.nb_instructions < ret.nb_instructions
				|| (test.nb_instructions == ret.nb_instructions && test.nb > ret.nb))
				ret = test;
		}
		current = current->next;
	}
	return (ret);
}
