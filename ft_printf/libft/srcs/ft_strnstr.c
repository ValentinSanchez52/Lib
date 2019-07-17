/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:50:10 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/16 17:33:03 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t				i;
	size_t				j;
	size_t				k;
	int					state;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	i = -1;
	while (haystack[++i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			k = i;
			state = 1;
			while (haystack[k] && needle[j] && j < len && k < len)
				if (needle[j++] != haystack[k++])
					state = 0;
			if (state && !needle[j])
				return ((char *)&haystack[i]);
		}
	}
	return (NULL);
}
