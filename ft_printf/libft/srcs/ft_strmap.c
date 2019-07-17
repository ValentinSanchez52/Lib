/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:19:45 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/25 17:32:36 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmap(const char *s, char (*f)(char))
{
	char		*dest;
	size_t		i;

	if (!s)
		return (NULL);
	i = -1;
	if (!(dest = ft_strdup(s)))
		return (NULL);
	while (++i < ft_strlen(s))
		dest[i] = f(s[i]);
	return (dest);
}
