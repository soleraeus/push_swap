/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:48:00 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/14 19:08:44 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_info *info, int nb)
{
	t_list	*current;

	current = info->begin_a;
	while (current)
	{
		if (current->nb == nb)
			return (1);
		current = current->next;
	}
	return (0);
}

static int	get_sign(const char *str, size_t *i)
{
	int	sign_factor;

	sign_factor = 1;
	while (str[*i] && (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\r'
			|| str[*i] == '\v' || str[*i] == '\f' || str[*i] == ' '))
		*i += 1;
	if (str[*i] && str[*i] == '-')
	{
		sign_factor = -1;
		*i += 1;
	}
	else if (str[*i] && str[*i] == '+')
		*i += 1;
	return (sign_factor);
}

long long	ft_atoll(const char *str)
{
	size_t		i;
	char		*nb_char;
	int			sign_factor;
	long long	ret;

	ret = 0;
	i = 0;
	sign_factor = get_sign(str, &i);
	nb_char = (char *)&str[i];
	i = 0;
	while (nb_char[i] && - ret >= INT_MIN)
	{
		ret = ret * 10 + nb_char[i] - '0';
		i++;
	}
	return ((long long)(sign_factor * ret));
}

int	check_nb(char *nb)
{
	int	i;

	i = 0;
	while (nb[i] == '\t' || nb[i] == '\n' || nb[i] == '\r' || nb[i] == '\v'
		|| nb[i] == '\f' || nb[i] == ' ')
		i++;
	if (nb[i] == '-' || nb[i] == '+')
		i++;
	if (nb[i] == '\0')
		return (1);
	while (nb[i])
	{
		if (!ft_isdigit(nb[i]))
			return (1);
		i++;
	}
	return (0);
}
