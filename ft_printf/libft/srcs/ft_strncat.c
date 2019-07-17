/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:38:08 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/09 10:40:59 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncat(char *dest, const char *src, size_t n)
{
	int				i;
	unsigned long	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && j < n)
		dest[i++] = src[j++];
	dest[i] = 0;
	return (dest);
}
