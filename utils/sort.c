#include "push_swap.h"


static t_moves	*pa_or_pb(t_info *info, int insert)
{
	t_moves	*ret;
	t_moves	mv_ins;

	ret = (t_moves *)malloc(sizeof(t_moves));
	if (!ret)
		return (NULL);
	*ret = find_best_move_remove(info);
	if (insert && info->size_b)
	{
		mv_ins = find_best_move_insert(info);
		if (mv_ins.target && mv_ins.nb_instructions <= ret->nb_instructions)
		{
			*ret = mv_ins;
			info->unordered += 1;
		}
	}
	execute_actions(info, ret, 0);
	info->unordered -= 1;
	return	(ret);
}


static t_instructions	*sortlist(t_info *info, int insert)
{
	t_instructions	*instructions;
	t_moves 		*nxt_mv;

	instructions = NULL;
	while (info->unordered != 0)
	{
			nxt_mv = pa_or_pb(info, insert);
			if (!nxt_mv)
				return (free_instructions(instructions), NULL);
			instructions = add_instruction(instructions, nxt_mv);
	}
	if (info->size_b != 0)
		instructions = ft_insertbtoa(info, instructions);
	instructions = finalrot(info, instructions);
	return (instructions);
}

static t_instructions	*keep_min(t_instructions *min, t_instructions *current)
{
	if (!current)
		return (free_instructions(min), NULL);
	if (current->tot_nb_instructions < min->tot_nb_instructions)
	{
		free_instructions(min);
		return (current);
	}
	free_instructions(current);
	return (min);
}

t_instructions	*sort(t_info **info)
{
	t_instructions	*min;

	min = sortlist(info[0], 0);
	if (!min)
		return (NULL);
	min = keep_min(min, sortlist(info[1], 1));
	if (!min)
		return (NULL);
	min = keep_min(min, sortlist(info[2], 0));
	if (!min)
		return (NULL);
	min = keep_min(min, sortlist(info[3], 1));
	if (!min)
		return (NULL);
	return (min);
}
