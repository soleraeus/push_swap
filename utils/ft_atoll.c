/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:50:54 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/14 19:06:09 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	lcl_getsign(const char *str, size_t *i)
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
	sign_factor = lcl_getsign(str, &i);
	nb_char = (char *)&str[i];
	i = 0;
	while (nb_char[i] && - ret >= INT_MIN)
	{
		ret = ret * 10 + nb_char[i] - '0';
		i++;
	}
	return ((long long)(sign_factor * ret));
}
