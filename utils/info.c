#include "push_swap.h"

void	free_info(t_info **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]->begin_a);
		free(tab[i]->begin_b);
		free(tab[i++]);
	}
	free(tab);
}

static void	init_info(t_info *info, int size)
{
	info->begin_a = NULL;
	info->last_a = NULL;
	info->min = NULL;
	info->maxsorted = NULL;
	info->size_a = size;
	info->unordered = 0;
	info->begin_b = NULL;
	info->last_b = NULL;
	info->size_b = 0;
	info->min_b = NULL;
	info->tot_size = size;
}

static void	cpy_info(t_info *dst, t_info *src)
{
	t_list	*current;

	dst->unordered = src->unordered;
	current = src->last_a;
	while (current != src->begin_a)
	{
		dst->begin_a = lst_addfront(dst->begin_a, current);
		if (current == src->last_a)
			dst->last_a = dst->begin_a;
		if (current == src->min)
			dst->min = dst->begin_a;
		if (current == src->maxsorted)
			dst->maxsorted = dst->begin_a;
		current = current->prev;
	}
	dst->begin_a = lst_addfront(dst->begin_a, current);
	if (current == src->min)
		dst->min = dst->begin_a;
	if (current == src->maxsorted)
		dst->maxsorted = dst->begin_a;
	dst->begin_a->prev = dst->last_a;
	dst->last_a->next = dst->begin_a;
}

static int	create_first_info(t_info *info, int ac, char **av)
{
	init_info(info, (ac - 1));

	while (ac-- > 1)
	{
		if (lstaddnbr(info[0], av[ac]))
			return (1);
	}
	findindex(info[0]);
	info[0]->begin_a->prev = info[0]->last_a;
	info[0]->last_a->next = info[0]->begin_a;
	ft_findwrongpos(info[0]);
	findmaxsorted(info[0]);
	return (0);
}

t_info	**create_tab(int ac, char **av)
{
	int	i;
	t_info	**info;

	info = (t_info **)malloc(sizeof(t_info *) * 5);
	if (!info)
		return (NULL);
	info[4] = NULL;
	i = -1;
	while (++i < 4)
	{
		info[i] = (t_info *)malloc(sizeof(t_info));
		if (!info[i])
			return (free_info(info), NULL);
		init_info(info[i], (ac - 1));
	}
	if (create_first_info(info[0], ac, av))
		return (free_info(info), NULL);
	if (info[0]->unordered == 0)
		return (info);
	while (++i < 4)
		cpy_info(info[i], info[0]);
	keep_min_only(info[2]);
	keep_min_only(info[3]);
}
