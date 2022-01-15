/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:52:28 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/15 15:54:41 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_instruction(char *action, char stack)
{
	if (action[1] != '\0')
		write(1, action, 2);
	else
		write(1, action, 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
}
