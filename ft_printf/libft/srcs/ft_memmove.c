/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:12:13 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/25 17:14:33 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void				*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*tmp;
	unsigned char	*srce;
	size_t			i;

	i = 0;
	srce = (unsigned char *)src;
	tmp = (unsigned char *)dest;
	if (tmp > srce)
		while ((int)--len >= 0)
			tmp[len] = srce[len];
	else
		while (i < len)
		{
			tmp[i] = srce[i];
			i++;
		}
	return (dest);
}
