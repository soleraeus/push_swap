#include "push_swap.h"
#include <stdio.h>

int	canswapnext(t_info *info, t_list *unordered)
{
	if (info->unordered == (info->size_a - 1))
		return (0);
	if (unordered->next->streak != -1 && unordered->next->index == (unordered->index - 1))
			return(1);
	return (0);
}

int	canswapprev(t_info *info, t_list *unordered)
{
	if (info->unordered == (info->size_a - 1))
		return (0);
	if (unordered->index == (info->tot_size - 1))
	{
		if (unordered->prev->index == 0)
			return (1);
		return (0);
	}
	if (unordered->prev->streak != -1 && unordered->prev->index == (unordered->index + 1))
		return (1);
	return (0);
}
