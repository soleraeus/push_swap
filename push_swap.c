/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:26:45 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/14 20:34:57 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
void	ft_sortlist(t_info *info)
{
	int		dist_from_begin;
	int		dist_from_last;
	t_list	*current;

}
*/

int	main(int ac, char **av)
{
	t_info	info;

	ft_initinfo(&info, (ac - 1));
	if (ac == 1)
		return (0);
	while (ac-- > 1)
		ft_lstaddnbr(&info, av[ac]);
	if (info.size_a == 1)
		return (ft_freelst(info.begin_a), 0);
	info.begin_a->prev = info.last_a;
	info.last_a->next = info.begin_a;
	ft_findwrongpos(&info);
	if (info.min->streak == info.size_a)
		return (ft_finalrotation(&info), ft_freelst(info.begin_a), 0);
//	ft_sortlist(&info);
	return (0);
}
