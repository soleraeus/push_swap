#include "push_swap.h"

void	free_tab_moves(t_moves **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_moves	*add_move(t_list *target, int dist)
{
	t_moves *possibility;

	possibility = (t_moves *)malloc(sizeof(t_moves));
	if (!possibility)
		return (NULL);
	possibility->target = target;
	possibility->block_end = NULL;
	possibility->dist = dist;
	possibility->size_block = 1;
	possibility->nb = target->nb;
	possibility->nb_instructions = 0;
	possibility->ra = 0;
	possibility->rb = 0;
	possibility->rr = 0;
	possibility->rra = 0;
	possibility->rrb = 0;
	possibility->rrr = 0;
	possibility->sa = 0;
	possibility->sb = 0;
	possibility->ss = 0;
	possibility->pa = 0;
	possibility->pb = 0;
	return (possibility);
}

void	init_target(t_moves *move)
{
	move->nb_instructions = 0;
	move->ra = 0;
	move->rb = 0;
	move->rr = 0;
	move->rra = 0;
	move->rrb = 0;
	move->rrr = 0;
	move->sa = 0;
	move->sb = 0;
	move->ss = 0;
	move->pa = 0;
	move->pb = 0;
}
