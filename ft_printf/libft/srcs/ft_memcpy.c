/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:59:28 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/08 15:57:35 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*tmp;
	const char		*srce;

	tmp = dest;
	srce = src;
	while (n)
	{
		*tmp = *srce;
		tmp++;
		srce++;
		n--;
	}
	return (dest);
}
