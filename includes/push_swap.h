/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:31:40 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/31 17:01:34 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
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

typedef struct s_moves
{
	t_list	*target;
	int		dist;
	int		nb;
	int		nb_op;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
}	t_moves;

typedef struct s_info
{
	t_list	*begin_a;
	t_list	*last_a;
	t_list	*min;
	t_list	*maxsort;
	int		size_a;
	int		unordered;
	t_list	*begin_b;
	t_list	*last_b;
	int		size_b;
	t_list	*min_b;
	int		lst_sz;
}	t_info;

typedef struct s_instructions
{
	int						tot_nb_op;
	t_moves					*moves;
	struct s_instructions	*first;
	struct s_instructions	*prev;
}	t_instructions;

void	ft_printlist(t_list *begin, t_list *last, char c);

void			throw_error(void);
t_info			**create_tab(int ac, char **av);
void			free_info(t_info **info);
int				check_nb(char *nb);
long long		ft_atoll(const char *str);
int				check_double(t_info *info, int nb);
int				lstaddnbr(t_info *info, char *av);
t_list			*lst_addfront(t_list *begin, t_list *current);
void			free_list(t_list *begin);
void			find_index(t_info *info);
void			find_wrong_pos(t_info *info);
void			find_max_sorted(t_info *info);
void			keep_min_only(t_info *info);
void			nb_pa(t_moves *move, t_list *first);
void			ft_bringtofront(t_info *info, t_moves *possibility, char stack);
int				getdist(t_list *begin, t_list *target);
void			execute_actions(t_info *info, t_moves *move, int print);
t_moves			best_mv_rm(t_info *info);
t_moves			best_mv_ins(t_info *info);
t_instructions	*finalrot(t_info *info, t_instructions *instructions);
void			ft_pusha(t_info *info);
void			ft_pushb(t_info *info);
void			swap_both(t_info *info);
void			swap_one(t_info *info, char stack);
void			ft_rotateone(t_list **begin, t_list **last);
void			ft_rotateboth(t_info *info);
void			ft_reverserotateone(t_list **begin, t_list **last);
void			ft_reverserotateboth(t_info *info);
t_instructions	*ft_insertbtoa(t_info *info, t_instructions *instructions);
int				ft_findinsertpos(t_info *info, int nb);
t_instructions	*add_instruction(t_instructions *instructions, t_moves *move);
t_instructions	*free_instructions(t_instructions *begin);
void			print_instructions(t_instructions *begin);
void			free_tab_moves(t_moves **tab);
void			push_or_swap(t_info *info, t_moves *mv);
void			ft_pushinorder(t_info *info, t_moves *possibility);
t_instructions	*sort(t_info **info);
int				tot_nb_moves(t_moves *mv);
void			optrot(t_info *info, t_moves *moves, int dist_a, int dist_b);
void			init_mv(t_moves *move, t_list *target, int dist);

#endif
