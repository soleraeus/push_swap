/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:31:40 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/11 13:50:07 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define WRONG_NUMBER "Error\n"
# define WRONG_NUMBER_SIZE 6

typedef struct s_list
{
	int				nb;
	struct s_list	*next;
}	t_list;

void		ft_throwerror(t_list **numbers);
void		ft_lstaddnbr(t_list **numbers, char *av);
int			ft_isdigit(int c);
void		ft_freelst(t_list **begin);
int			ft_checknb(char *nb);
long long	ft_atoll(const char *str);
void		ft_checkdouble(t_list **numbers, int nb);
void		ft_swapone(t_list **begin);
void		ft_swapboth(t_list **numbers_a, t_list **numbers_b);
void		ft_push(t_list **dst, t_list **src);
void		ft_rotateone(t_list **begin);
void		ft_rotateboth(t_list **numbers_a, t_list **numbers_b);
void		ft_reverserotateone(t_list **begin);
void		ft_reverserotateboth(t_list **numbers_a, t_list **numbers_b);

#endif
