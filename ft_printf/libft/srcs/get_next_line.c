/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:05:41 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/10 18:04:26 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t		ft_getchar_index(const char *buff, char c, int *found)
{
	const char	*tmp;

	tmp = buff;
	while (*buff)
	{
		if (*buff == c && (*found = 1))
			return (buff - tmp);
		buff++;
	}
	*found = 0;
	return (buff - tmp);
}

static t_buffer_fd	*buffer_creator(int fd)
{
	t_buffer_fd	*tmp;

	if (!((tmp = (t_buffer_fd*)malloc(sizeof(t_buffer_fd)))
				&& (tmp->buff = (char *)ft_memalloc(BUFF_SIZE + 1))))
		return (NULL);
	tmp->fd = fd;
	tmp->next = NULL;
	return (tmp);
}

static t_buffer_fd	*buffer_selector(int fd, t_buffer_fd **b, char **l)
{
	t_buffer_fd	*tmp;

	*l = NULL;
	if (!(*b))
		return (*b = buffer_creator(fd));
	tmp = *b;
	while (tmp->fd != fd && tmp->next)
		tmp = tmp->next;
	if (tmp->fd != fd)
		return (tmp->next = buffer_creator(fd));
	else
		return (tmp);
}

int					get_next_line(int fd, char **line)
{
	static t_buffer_fd	*static_buffer;
	t_buffer_fd			*tmp;
	int					i;
	int					found;
	size_t				size;

	if (!(fd >= 0 && BUFF_SIZE > 0 && line
				&& (tmp = buffer_selector(fd, &static_buffer, line))))
		return (-1);
	size = 0;
	i = 0;
	found = 0;
	while (!(found))
	{
		if (!tmp->buff[0] && ((tmp->ret = read(fd, tmp->buff, BUFF_SIZE)) <= 0))
			return ((!tmp->buff[0] && *line) ? 1 : tmp->ret);
		i = ft_getchar_index(tmp->buff, '\n', &found);
		if (!((*line = (char*)ft_realloc(*line, size, i))))
			return (-1);
		ft_strncpy(*line + size, tmp->buff, i);
		ft_strncpy(tmp->buff, tmp->buff + i + found, BUFF_SIZE - i - found);
		ft_bzero(tmp->buff + BUFF_SIZE - i - found, i + found);
		size += i;
	}
	return (1);
}
