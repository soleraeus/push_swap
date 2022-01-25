#include "push_swap.h"

static t_list	*lst_addfront(t_list *begin, t_list *current)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->nb = current->nb;
	new->index = current->index;
	new->streak = current->streak;
	current->next = begin;
	current->prev = NULL;
	return (new);
}

static void	cpy_lst(t_info *dst, t_info *src)
{
	t_list	*current;

	current = src->last_a;
	while (current != src->begin_a)
	{
		dst->begin_a = lst_addfront(dst->begin_a, current);
		if (current == src->last_a)
			dst->last_a = dst_begin_a;
		if (current == src->min)
			dst->min = dst->begin_a;
		if (current == scr->maxsorted)
			dst->maxsorted = dst->begin_a;
		current = current->prev;
	}
	dst->begin_a = lst_addfront(dst->begin_a, current);
	if (current == src->min)
		dst->min = dst->begin_a;
	if (current == scr->maxsorted)
		dst->maxsorted = dst->begin_a;
	dst->begin_a->prev = dst->last_a;
	dst->last_a->next = dst->begin_a;
}

void	cpy_info(t_info *dst, t_info *src)
{
	dst->begin_a = NULL;
	dst->last_a = NULL;
	dst->min = NULL;
	dst->maxsorted = NULL;
	dst->size_a = src->size_a;
	dst->unordered = src->unordered;
	dst->begin_b = NULL;
	dst->last_b = NULL;
	dst->size_b = 0;
	dst->min_b = NULL;
	dst->tot_size = src->tot_size;
	cpy_lst(dst, src);
}
