/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:14:31 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/27 14:28:37 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *begin)
{
	t_list	*next;

	if (!begin)
		return ;
	if (begin->prev)
		begin->prev->next = NULL;
	while (begin)
	{
		next = begin->next;
		free(begin);
		begin = next;
	}
}

t_list	*lst_addfront(t_list *begin, t_list *current)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->nb = current->nb;
	new->index = current->index;
	new->streak = current->streak;
	new->next = begin;
	new->prev = NULL;
	if (begin)
		begin->prev = new;
	return (new);
}

static t_list	*lst_new(int nb)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->index = -1;
	new->prev = NULL;
	new->next = NULL;
	new->streak = 1;
	return (new);
}

int	lstaddnbr(t_info *info, char *av)
{
	long long	nb;
	t_list		*new;

	if (check_nb(av))
		return (throw_error(), 1);
	nb = ft_atoll(av);
	if (nb > INT_MAX || nb < INT_MIN || check_double(info, nb))
		return (throw_error(), 1);
	new = lst_new((int)nb);
	if (!new)
		return (1);
	new->next = info->begin_a;
	if (!info->begin_a)
	{
		info->min = new;
		info->last_a = new;
	}
	else
		info->begin_a->prev = new;
	if (info->min && info->min->nb > new->nb)
		info->min = new;
	info->begin_a = new;
	return (0);
}
