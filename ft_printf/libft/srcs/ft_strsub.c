/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:45:14 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/16 19:44:12 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char		*dest;

	if (!s)
		return (NULL);
	if (!(dest = ft_strnew(len)))
		return (NULL);
	s += start;
	ft_strncpy(dest, s, len);
	return (dest);
}
