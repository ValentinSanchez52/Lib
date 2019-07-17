/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:58:05 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/16 19:03:34 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static size_t	ft_nblen(int n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			nblen;
	unsigned int	temp;

	nblen = ft_nblen(n);
	temp = n;
	if (n < 0)
	{
		nblen++;
		temp = -n;
	}
	if (!(str = ft_strnew(nblen)))
		return (NULL);
	str[--nblen] = temp % 10 + '0';
	while (temp /= 10)
		str[--nblen] = temp % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
