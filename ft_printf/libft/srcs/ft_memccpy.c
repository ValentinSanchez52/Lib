/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:06:57 by vsanchez          #+#    #+#             */
/*   Updated: 2019/06/06 23:16:25 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char			*tmp;
	size_t			i;

	i = 0;
	tmp = dest;
	while (i < n)
	{
		tmp[i] = *((unsigned char *)(src + i));
		if ((*(unsigned char *)(src + i)) == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
