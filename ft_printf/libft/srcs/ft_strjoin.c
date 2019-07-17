/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:52:09 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/16 19:45:47 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(const char *s1, const char *s2)
{
	char		*dest;

	if (!(s1 && s2))
		return (NULL);
	if (!(dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcat(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}
