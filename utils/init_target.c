/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:59:28 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/19 12:00:42 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_target(t_moves *possibility)
{
	possibility->nb_instructions = 0;
	possibility->ra = 0;
	possibility->rb = 0;
	possibility->rr = 0;
	possibility->rra = 0;
	possibility->rrb = 0;
	possibility->rrr = 0;
	possibility->sa = 0;
	possibility->sb = 0;
	possibility->ss = 0;
	possibility->pa = 0;
	possibility->pb = 0;
}
