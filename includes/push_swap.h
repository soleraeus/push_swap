/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:31:40 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/22 08:28:04 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define WRONG_NUMBER "Error\n"
# define WRONG_NUMBER_SIZE 6
# define TARGET_NB 500

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
	t_list	*block_end;
	int		dist;
	int		size_block;
	int		nb;
	int		nb_instructions;
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
	t_list	*maxsorted;
	int		size_a;
	int		unordered;
	t_list	*begin_b;
	t_list	*last_b;
	int		size_b;
	t_list	*min_b;
	int		tot_size;
}	t_info;

typedef struct s_instructions
{
	int						tot_nb_instructions;
	t_moves					*moves;
	struct s_instructions	*first;
	struct s_instructions	*prev;
}	t_instructions;

void	ft_printlist(t_list **begin, t_list **last, char c);

t_moves		*cpy_move(t_moves *src);
t_moves		*add_possibility(t_info *info, t_list *target, int dist);
t_instructions	*add_instruction(t_instructions *instructions, t_moves *move);
void			simulate_actions(t_info *info, t_moves *possibility);
void			findmaxsorted(t_info *info);
void			optimize_rotations(t_info *info, t_moves *moves, int dist_a, int dist_b);
int				getdist(t_list *begin, int size, t_list *target);
void			ft_initinfo(t_info *info, int size);
void			ft_throwerror(t_info *info);
void			ft_lstaddnbr(t_info *info, char *av);
int				ft_isdigit(int c);
void			ft_freelst(t_list *begin);
int				ft_checknb(char *nb);
long long		ft_atoll(const char *str);
int				tot_nb_moves(t_moves *possibility);
void			ft_checkdouble(t_info *info, int nb);
void			findindex(t_info *info);
t_moves			**ft_findtargets(t_info *info);
t_moves			**ft_findblocks(t_info *info);
void			execute_actions(t_instructions *min);
void			init_target(t_moves *possibility);
void			free_possibilities(t_moves **tab);
void			ft_findwrongpos(t_info *info);
void			ft_swapone(t_list **begin);
void			ft_swapboth(t_info *info);
void			ft_pusha(t_info *info);
void			ft_pushb(t_info *info);
void			ft_rotateone(t_list **begin, t_list **last);
void			ft_rotateboth(t_info *info);
void			ft_reverserotateone(t_list **begin, t_list **last);
void			ft_reverserotateboth(t_info *info);
int				ft_findclosest(t_info *info, t_list **unordered);
int				canswapnext(t_info *info, t_list *unordered);
int				canswapprev(t_info *info, t_list *unordered);
int				ft_findnextvalid(t_list *begin);
int				ft_findprevvalid(t_list *begin);
void			ft_bringtofront(t_info *info, t_moves *possibility, char stack);
void			ft_pushinorder(t_info *info, t_moves *possibility);
t_instructions	*ft_insertbtoa(t_info *info, t_instructions *instructions);
t_instructions	*ft_finalrotation(t_info *info, t_instructions *instructions);

#endif
