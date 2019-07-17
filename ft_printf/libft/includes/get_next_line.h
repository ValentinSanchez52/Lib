/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:04:15 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 14:05:34 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int				get_next_line(const int fd, char **line);

typedef struct	s_buffer_fd
{
	struct s_buffer_fd	*next;
	char				*buff;
	int					fd;
	int					ret;
}				t_buffer_fd;

#endif
