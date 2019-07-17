/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fd_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <vsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:35:38 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/14 12:56:50 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				ft_t_strcat(t_str *string, char *buff,
		ssize_t str_len)
{
	uint64_t			new_len;

	if (!buff || !string)
		return ;
	new_len = string->str_len + str_len;
	if (new_len >= string->capacity)
	{
		if (!(string->str = ft_realloc(string->str, string->capacity,
						string->capacity)))
			ft_print_error("reallocation in ft_t_strcat failed");
		string->capacity *= 2;
		return (ft_t_strcat(string, buff, str_len));
	}
	else
	{
		ft_memcpy(string->str + string->str_len, buff, str_len);
		string->str_len = new_len;
	}
}

void					ft_get_fd_content(t_str *string, int fd)
{
	static char		buff[BUFF_SIZE];
	ssize_t			n;

	while ((n = read(fd, buff, sizeof(buff))) > 0)
		ft_t_strcat(string, buff, n);
}
