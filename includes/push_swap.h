/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:31:40 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/14 20:36:42 by bdetune          ###   ########.fr       */
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
	int				index;
	int				streak;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_info
{
	t_list	*begin_a;
	t_list	*last_a;
	t_list	*min;
	int		size_a;
	t_list	*begin_b;
	t_list	*last_b;
	int		size_b;
}	t_info;

void		ft_initinfo(t_info *info, int size);
void		ft_throwerror(t_info *info);
void		ft_lstaddnbr(t_info *info, char *av);
int			ft_isdigit(int c);
void		ft_freelst(t_list *begin);
int			ft_checknb(char *nb);
long long	ft_atoll(const char *str);
void		ft_checkdouble(t_info *info, int nb);
void		ft_findwrongpos(t_info *info);
void		ft_swapone(t_list **begin);
void		ft_swapboth(t_info *info);
void		ft_pusha(t_info *info);
void		ft_pushb(t_info *info);
void		ft_rotateone(t_list **begin, t_list **last);
void		ft_rotateboth(t_info *info);
void		ft_reverserotateone(t_list **begin, t_list **last);
void		ft_reverserotateboth(t_info *info);
void		ft_finalrotation(t_info *info);

#endif
