/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:00:05 by vsanchez          #+#    #+#             */
/*   Updated: 2019/06/06 23:16:52 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*sbis;
	size_t					i;
	unsigned char			cbis;

	sbis = s;
	i = 0;
	cbis = c;
	while (i < n)
	{
		if (sbis[i] == cbis)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
