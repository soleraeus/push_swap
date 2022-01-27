#include "push_swap.h"

static t_instructions	*sortlist_insert(t_info *info)
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
				simulate_actions(info, possibility_insert);
				instructions = add_instruction(instructions, possibility_insert);
				free(possibility_remove);
			}
			else
			{
				simulate_actions(info, possibility_remove);
				instructions = add_instruction(instructions, possibility_remove);
				free(possibility_insert);
				info->unordered -= 1;
			}
		}
		else
		{
			simulate_actions(info, possibility_remove);
			instructions = add_instruction(instructions, possibility_remove);
			info->unordered -= 1;
		}
	}
	if (info->size_b != 0)
		instructions = ft_insertbtoa(info, instructions);
	instructions = ft_finalrotation(info, instructions);
	return (instructions);
}

static t_instructions	*sortlist(t_info *info)
{
	t_instructions	*instructions;
	t_instructions	*new;
	t_moves 		*move;

	instructions = NULL;
	while (info->unordered != 0)
	{
		move = NULL;
		move = find_best_move_remove(info);
		if (!move)
			return (free_instructions(instructions), NULL)
		execute_actions(info, move, 0);
		new = add_instruction(instructions, move);
		if (!new)
			return (free_instructions(instructions), free(move), NULL);
		instructions = new;
		info->unordered -= 1;
	}
	if (info->size_b != 0)
		instructions = ft_insertbtoa(info, instructions);
	instructions = ft_finalrotation(info, instructions);
	return (instructions);
}


static t_instructions	*keep_min(t_instructions *min, t_instructions *current)
{
	if (!current)
		return (free_instructions(min));
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
	t_instructions	*current;

	min = sortlist(info[0]);
	if (!min)
		return (NULL);
	min = keep_min(min, sortlist_insert(info[1]));
	if (!min)
		return (NULL);
	min = keep_min(min, sortlist_insert(info[2]));
	if (!min)
		return (NULL);
	min = keep_min(min, sortlist(info[3]));
	if (!min)
		return (NULL);
	return (min)
}
