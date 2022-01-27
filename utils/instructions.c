#include "push_swap.h"

void	print_instructions(t_instructions *begin)
{
	t_instructions	*current;
	t_instructions	*swap;

	current = begin->first;
	while (current)
	{
		execute_actions(NULL, current->moves, 1);
		swap = current->prev;
		free(current->moves);
		free(current);
		current = swap;
	}
}

t_instructions	*free_instructions(t_instructions *begin)
{
	t_instructions	*swap;
	t_instructions	*current;

	if (!begin)
		return (NULL);
	current = begin->first;
	while (current)
	{
		free(current->moves);
		swap = current->prev;
		free(current);
		current = swap;
	}
	return (NULL);
}

t_instructions	*add_instruction(t_instructions *instructions, t_moves *move)
{
	t_instructions	*new;

	new = (t_instructions *)malloc(sizeof(t_instructions));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->moves = move;
	if (move->pa)
		new->tot_nb_instructions = move->nb_instructions - 1 + move->pa;
	else
		new->tot_nb_instructions = move->nb_instructions;
	if (!instructions)
		new->first = new;
	else
	{
		new->first = instructions->first;
		new->tot_nb_instructions += instructions->tot_nb_instructions;
		instructions->prev = new;
	}
	return (new);
}
