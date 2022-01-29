#include "push_swap.h"

static t_list	*can_push_back(t_info *info, t_moves *move)
{
	t_list	*current;

	if (info->maxsorted == info->min)
	{
		if (move->target->index == (info->tot_size - 1))
			return (info->min);
		return (NULL);
	}
	current = info->maxsorted;
	while (current->prev->index == (current->index - 1))
		current = current->prev;
	if (move->target->index == (current->index - 1))
		return (current);
	return (NULL);
}

t_moves	*find_best_move_insert(t_info *info)
{
	int		i;
	t_list	*loc_a;
	t_moves	*ret;
	t_moves	**tab;
	
	loc_a = NULL;
	tab = find_blocks(info);
	if (!tab)
		return (NULL);
	ret = (t_moves *)malloc(sizeof(t_moves));
	if (!ret)
		return (free_tab_moves(tab), NULL);
	ret->target = NULL;
	i = 0;
	while (tab[i])
	{
		loc_a = can_push_back(info, tab[i]);
		if (loc_a)
			break ;
		i++;
	}
	if (loc_a)
	{
		*ret = *(tab[i]);
		optrot(info, ret, getdist(info->begin_a, info->size_a, loc_a), ret->dist);
		ret->pa = 1;
		tot_nb_moves(ret);
		ret->pa = ret->size_block;
	}		
	return (free_tab_moves(tab), ret);
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
