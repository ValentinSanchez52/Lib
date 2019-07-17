/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:02:25 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/16 18:46:40 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *s, int c)
{
	int			i;

	i = ft_strlen(s) + 1;
	while (i--)
		if (s[i] == c)
			return ((char *)&s[i]);
	return (NULL);
}
