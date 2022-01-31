/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:31:25 by bdetune           #+#    #+#             */
/*   Updated: 2022/01/31 20:32:17 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
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

char		*get_next_line(int fd);
void		internal_get_str(int fd, t_openfd *current, \
			int start_index, int *nl_pos);
char		*internal_join(char *dst, char *src);
char		*internal_getremainer(char *remainer, int nl_pos);
char		*internal_get_line(char *remainer, int *nl_pos);
int			internal_hasnl(char *str, int *start_index, int *nl_pos);
t_openfd	*internal_findfd(t_openfd **begin, int fd);

#endif
