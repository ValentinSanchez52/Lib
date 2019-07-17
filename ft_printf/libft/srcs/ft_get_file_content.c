/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <vsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:03:44 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 19:09:09 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char						*ft_get_file_content(char *filename)
{
	t_str		string;
	int			fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	string.capacity = 256;
	if (!(string.str = (char *)ft_memalloc(sizeof(char) * string.capacity)))
		return (NULL);
	string.str_len = 0;
	ft_get_fd_content(&string, fd);
	close(fd);
	return (string.str);
}
