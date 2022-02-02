/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:26:45 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/31 20:14:25 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	throw_error(void)
{
	write(2, "Error\n", 6);
}

int	main(int ac, char **av)
{
	t_info	**info;
	t_moves	*mv_lst;

	if (ac == 1)
		return (0);
	info = create_tab(ac, av);
	if (!info)
		return (1);
	if (info[0]->unordered == 0)
	{
		mv_lst = finalrot(info[0], NULL);
		if (!mv_lst)
			return (free_info(info), 1);
		return (print_mv_lst(mv_lst), free_info(info), 0);
	}
	mv_lst = sort(info);
	if (!mv_lst)
		return (free_info(info), 1);
	return (print_mv_lst(mv_lst), free_info(info), 0);
}
