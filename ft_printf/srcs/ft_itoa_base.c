/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:13:46 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:24 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int		ft_nbrlen(unsigned long l, unsigned long base)
{
	int				nb;

	nb = 0;
	while (l > 0)
	{
		nb++;
		l = l / base;
	}
	return (nb);
}

static inline char		*ft_zero_int_min(int n)
{
	if (n == INT_MIN)
		return (ft_strdup("-2147483647"));
	return (ft_strdup("0"));
}

char					*ft_itoa_base(int n, int base)
{
	unsigned long		nb;
	char				*str;
	int					i;

	if (n == INT_MIN || n == 0)
		return (ft_zero_int_min(n));
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
		str[i] = (nb % base) + '0';
		nb = nb / base;
		i++;
	}
	if (n < 0)
		str[i] = '-';
	return (ft_strrev(str));
}
