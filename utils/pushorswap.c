#include "push_swap.h"
#include <stdio.h>

void	ft_pushinorder(t_info *info, t_moves *possibility)
{
	int		nb;
	int		dist_b;
	t_list	*current;

	nb = possibility->nb;
	if (info->size_b == 0 || info->size_b == 1)
	{
		ft_bringtofront(info, possibility, 'a');
		possibility->pb += 1;
		return ;
	}
	dist_b = 0;
	current = info->begin_b;
	while (1)
	{
		if ((current->nb < nb
			&& (current->prev->nb > nb || current->prev == info->min_b))
			|| (nb < info->min_b->nb && current->prev == info->min_b) )
			break;
		dist_b++;
		current = current->next;
	}
	optimize_rotations(info, possibility, possibility->dist, dist_b);
	possibility->pb += 1;
}

static int	canswapnext(t_info *info, t_list *unordered)
{
	if (info->unordered == (info->size_a - 1))
		return (0);
	if (unordered->next->streak != -1
		&& unordered->next->index == (unordered->index - 1))
			return(1);
	return (0);
}

static int	canswapprev(t_info *info, t_list *unordered)
{
	if (info->unordered == (info->size_a - 1))
		return (0);
	if (unordered->index == (info->tot_size - 1))
	{
		if (unordered->prev->index == 0)
			return (1);
		return (0);
	}
	if (unordered->prev->streak != -1 
		&& unordered->prev->index == (unordered->index + 1))
		return (1);
	return (0);
}

void	ft_pushorswap(t_info *info, t_moves *possibility)
{
	t_moves	posswapnext;

	posswapnext = *possibility;
	if (canswapnext(info, possibility->target))
	{
		ft_bringtofront(info, &posswapnext, 'a');
		posswapnext.sa += 1;
	}
	if (canswapprev(info, possibility->target))
	{
		possibility->dist -= 1;
		ft_bringtofront(info, possibility, 'a');
		possibility->sa += 1;
		if (tot_nb_moves(&posswapnext) < tot_nb_moves(possibility)
			&& posswapnext.sa)
			*possibility = posswapnext;
		return ;
	}
	if (posswapnext.sa)
	{
		*possibility = posswapnext;
		tot_nb_moves(possibility);
		return ;
	}
		ft_pushinorder(info, possibility);
	tot_nb_moves(possibility);
}
