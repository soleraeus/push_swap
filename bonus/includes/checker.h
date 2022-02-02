/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:31:25 by bdetune           #+#    #+#             */
/*   Updated: 2022/02/02 20:22:19 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFFER_SIZE 25
# include <limits.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_openfd
{
	int				fd;
	char			*remainer;
	struct s_openfd	*next;
}	t_openfd;

typedef struct s_inst
{
	char			*inst;
	struct s_inst	*first;
	struct s_inst	*prev;
}	t_inst;

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
	int		size_a;
	t_list	*begin_b;
	t_list	*last_b;
	int		size_b;
	int		lst_sz;
}	t_info;

char		*get_next_line(int fd);
void		internal_get_str(int fd, t_openfd *current, \
			int start_index, int *nl_pos);
char		*internal_join(char *dst, char *src);
char		*internal_getremainer(char *remainer, int nl_pos);
char		*internal_get_line(char *remainer, int *nl_pos);
int			internal_hasnl(char *str, int *start_index, int *nl_pos);
t_openfd	*internal_findfd(t_openfd **begin, int fd);
void		throw_error(void);
int			create_info(t_info *info, int ac, char **av);
void		free_info(t_info *info);
int			execute_inst(t_info *info, t_inst *inst_lst);
t_inst		*add_inst(t_inst *inst_lst, char *inst);
void		free_inst(t_inst *inst_lst);
int			lstaddnbr(t_info *info, char *av);
void		free_list(t_list *begin);
int			check_nb(char *nb);
long long	ft_atoll(const char *str);
int			check_double(t_info *info, int nb);
void		push_a(t_info *info);
void		push_b(t_info *info);
void		rot_one(t_list **begin, t_list **last);
void		rot_both(t_info *info);
void		rev_rot_one(t_list **begin, t_list **last);
void		rev_rot_both(t_info *info);
void		swap_one(t_info *info, char st);
void		swap_both(t_info *info);

#endif
