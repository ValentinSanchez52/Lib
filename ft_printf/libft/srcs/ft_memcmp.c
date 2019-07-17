/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:40:03 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/16 15:33:10 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*s1bis;
	unsigned char		*s2bis;
	size_t				i;

	s1bis = (unsigned char *)s1;
	s2bis = (unsigned char *)s2;
	i = 0;
	while (i < n && s1bis[i] == s2bis[i])
		i++;
	if (i == n)
		return (0);
	return (s1bis[i] - s2bis[i]);
}
