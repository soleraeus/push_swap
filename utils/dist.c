#include "push_swap.h"

int	getdist(t_list *begin, int size, t_list *target)
{
	int		dist;
	t_list	*current;

	(void)size;
	dist = 0;
	current = begin;
	while (current != target)
	{
		dist++;
		current = current->next;
	}
	return (dist);
}

void	ft_bringtofront(t_info *info, t_moves *possibility, char stack)
{
	int	dist;

	dist = possibility->dist;
	if (stack == 'a' && (info->size_a - dist) < dist)
		dist = -(info->size_a - dist);
	if  (stack == 'b' && (info->size_b - dist) < dist)
		dist = -(info->size_b - dist);
	while (dist < 0)
	{
		if 	(stack == 'a')
			possibility->rra += 1;
		else
			possibility->rrb += 1;
		dist++;
	}
	while (dist > 0)
	{
		if 	(stack == 'a')
			possibility->ra += 1;
		else
			possibility->rb += 1;
		dist--;
	}
}
