/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stdin_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <vsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:03:44 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 19:09:21 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char						*ft_get_stdin_content(void)
{
	t_str	string;

	string.capacity = 256;
	if (!(string.str = (char *)ft_memalloc(sizeof(char) * string.capacity)))
		return (NULL);
	string.str_len = 0;
	ft_get_fd_content(&string, 0);
	return (string.str);
}
