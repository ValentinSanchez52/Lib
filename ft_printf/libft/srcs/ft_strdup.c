/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:29:48 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/08 13:05:33 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				*ft_strdup(const char *src)
{
	char			*dest;

	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}
