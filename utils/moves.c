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

void	init_mv(t_moves *move, t_list *target, int dist)
{
	move->target = target;
	move->dist = dist;
	move->nb = target->nb;
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
