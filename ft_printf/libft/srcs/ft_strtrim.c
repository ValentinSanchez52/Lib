/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:52:21 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/16 19:46:14 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char			*ft_strtrim(const char *s)
{
	int			len;
	char		*dest;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == 0)
		dest = ft_strnew(1);
	else
	{
		len = ft_strlen(s);
		while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n' || s[len] == 0)
			len--;
		if (!(dest = ft_strnew(len + 2)))
			return (NULL);
		ft_strncpy(dest, s, len + 1);
		dest[len + 2] = 0;
	}
	return (dest);
}
