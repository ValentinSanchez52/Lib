/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:47:59 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:25 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int	ft_nbrlen(unsigned long long l, unsigned long long base)
{
	int		nb;

	nb = 0;
	while (l > 0)
	{
		nb++;
		l = l / base;
	}
	return (nb);
}

char				*ft_ulltoa_base(unsigned long long n, int base)
{
	unsigned long long	nb;
	char				*str;
	int					i;

	nb = ft_absolute_int(n);
	i = 0;
	if (!(str = ft_strnew(ft_nbrlen(nb, base))))
		return ("(null)");
	if (n == 0)
	{
		str[i] = '0';
		return (ft_strdup(str));
	}
	while (nb > 0)
	{
		str[i] = (nb % base) + (nb % base > 9 ? 'a' - 10 : '0');
		nb = nb / base;
		i++;
	}
	return (ft_strrev(str));
}
