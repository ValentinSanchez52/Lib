/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:41:17 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/09 11:25:49 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	if (size < ft_strlen(dest))
		return (size + ft_strlen(src));
	i = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	j = i;
	while (src[i - j] && i < (size - 1))
	{
		dest[i] = src[i - j];
		i++;
	}
	if (j < size)
		dest[i] = '\0';
	return (j + ft_strlen(src));
}
