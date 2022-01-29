#include "push_swap.h"

t_moves	*find_best_move_insert(t_info *info)
{
	int		i;
	t_list	*it;
	t_moves	*ret;
	
	info->last_b->next = NULL;
	ret = (t_moves *)malloc(sizeof(t_moves));
	if (!ret)
		return (NULL);
	ret->target = NULL;
	it = info->begin_b;
	i = 0;
	while (it)
	{
		if (it->index == (info->maxsorted->index - 1))
		{
			reinitmove(ret, it, i);
			break ;
		}
		i++;
		it = it->next;
	}
	info->last_b->next = info->begin_b;
	if (ret->target)
	{
		optrot(info, ret, getdist(info->begin_a, info->size_a, info->maxsorted), i);
		ret->pa = 1;
		tot_nb_moves(ret);
		ret->target->prev->next = NULL;
		nb_pa(ret, ret->target);
	}		
	return (ret);
}


t_moves	*find_best_move_remove(t_info *info)
{
	t_moves	*ret;
	t_moves	test;
	t_list	*current;

	ret = (t_moves *)malloc(sizeof(t_moves));
	if (!ret)
		return (NULL);
	ret->target = NULL;
	current = info->min->next;;
	while (current != info->min)
	{
		if (current->streak == -1)
		{
			reinitmove(&test, current, getdist(info->begin_a, info->size_a, current));
			ft_pushorswap(info, &test);
			if (ret->target == NULL || test.nb_instructions < ret->nb_instructions
				|| (test.nb_instructions == ret->nb_instructions && test.nb > ret->nb))
				*ret = test;
		}
		current = current->next;
	}
	return (ret);
}
