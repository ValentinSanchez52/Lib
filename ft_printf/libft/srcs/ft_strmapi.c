/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:24:04 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/25 17:32:50 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char		*dest;
	size_t		i;

	if (!s)
		return (NULL);
	i = -1;
	if (!(dest = ft_strdup(s)))
		return (NULL);
	while (++i < ft_strlen(s))
		dest[i] = f(i, s[i]);
	return (dest);
}
