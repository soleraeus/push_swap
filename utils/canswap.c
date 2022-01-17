#include "push_swap.h"

int	canswapnext(t_info *info, t_list *unordered)
{
	int	next_valid_val;

	if (unordered->next->streak != -1 && unordered->next->nb < unordered->nb)
	{
		next_valid_val = ft_findnextvalid(unordered->next->next);
		if (next_valid_val > unordered->nb || next_valid_val == info->min->nb)
			return(1);
	}
	return (0);
}

int	canswapprev(t_info *info, t_list *unordered)
{
	int	prev_valid_val;
		
	if (unordered->prev->streak != -1 && (unordered->prev->nb > unordered->nb || unordered->prev->nb == info->min->nb))
	{
		prev_valid_val = ft_findprevvalid(unordered->prev->prev);
		if (prev_valid_val < unordered->nb)
			return (1);
	}
	return (0);
}
