/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:59:11 by bdetune           #+#    #+#             */
/*   Updated: 2021/12/07 18:00:19 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	internal_get_str(int fd, t_openfd *current, \
		int start_index, int *nl_pos)
{
	int		ret;
	char	*buffer;
	char	*new_remainer;

	if (internal_hasnl(current->remainer, &start_index, nl_pos))
		return ;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return ;
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret <= 0)
	{
		free (buffer);
		return ;
	}
	buffer[ret] = '\0';
	new_remainer = internal_join(current->remainer, buffer);
	free(current->remainer);
	free(buffer);
	current->remainer = new_remainer;
	internal_get_str(fd, current, start_index, nl_pos);
}

t_openfd	*internal_findfd(t_openfd **begin, int fd)
{
	t_openfd	*new;
	t_openfd	*current;

	current = *begin;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	new = (t_openfd *)malloc(sizeof(t_openfd));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->remainer = NULL;
	new->next = *begin;
	*begin = new;
	return (new);
}

void	free_elt(t_openfd **begin, t_openfd *current)
{
	t_openfd	*previous;
	t_openfd	*next;

	if (*begin == current)
	{
		*begin = current->next;
		free(current);
		return ;
	}
	next = *begin;
	while (next != current)
	{
		previous = next;
		next = next->next;
	}
	previous->next = next->next;
	free(current);
}

char	*get_next_line(int fd)
{
	static t_openfd	*opened = NULL;
	t_openfd		*current;
	char			*line;
	char			*new_remainer;
	int				nl_pos;

	line = NULL;
	nl_pos = -1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current = internal_findfd(&opened, fd);
	if (!current)
		return (NULL);
	internal_get_str(fd, current, 0, &nl_pos);
	line = internal_get_line(current->remainer, &nl_pos);
	new_remainer = internal_getremainer(current->remainer, (nl_pos + 1));
	free(current->remainer);
	if (!new_remainer)
		free_elt(&opened, current);
	else
		current->remainer = new_remainer;
	return (line);
}
