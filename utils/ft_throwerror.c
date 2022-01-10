/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throwerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:03:54 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/10 20:05:53 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_throwerror(t_list **numbers)
{
	ft_freelst(numbers);
	write(2, WRONG_NUMBER, WRONG_NUMBER_SIZE);
	exit(1);
}
