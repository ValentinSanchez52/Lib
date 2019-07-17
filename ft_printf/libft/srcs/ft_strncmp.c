/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:45:35 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/16 17:22:38 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned char		*s1bis;
	unsigned char		*s2bis;
	unsigned long		i;

	s1bis = (unsigned char *)s1;
	s2bis = (unsigned char *)s2;
	i = 0;
	while (i < len - 1 && s1bis[i] == s2bis[i] && s1bis[i] != 0)
		i++;
	if (i == len)
		return (0);
	return (s1bis[i] - s2bis[i]);
}
