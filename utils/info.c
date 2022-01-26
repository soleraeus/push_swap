#include "push_swap.h"

void	free_info(t_info **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
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

static int	create_first_info(t_info *info, int ac, char **av)
{
	init_info(info, (ac - 1));

	while (ac-- > 1)
		ft_lstaddnbr(info[0], av[ac]);
	if (info[0]->size_a == 1)
		return (free(info[0]->begin_a), 0);
	findindex(info[0]);
	info[0]->begin_a->prev = info[0]->last_a;
	info[0]->last_a->next = info[0]->begin_a;
	ft_findwrongpos(info[0]);
	findmaxsorted(info[0]);

}

t_info	**create_tab(int ac, char **av)
{
	int	i;
	t_info	**info;

	if (ac == 1)
		return (NULL);
	info = (t_info **)malloc(sizeof(t_info *) * 5);
	if (!info)
		return (NULL);
	info[4] = NULL;
	i = -1;
	while (++i < 4)
	{
		info[i] = (t_info *)malloc(sizeof(t_info));
		if (!info[i])
			return (free_info(tab), NULL);
	}
	create_first_info(info[0], ac, av);
	while (++i < 4)
	{
		info[i] = (t_info *)malloc(sizeof(t_info));
		cpy_info(info[i], info[0]);
	}
	keep_min_only(info[2]);
	keep_min_only(info[3]);
}
