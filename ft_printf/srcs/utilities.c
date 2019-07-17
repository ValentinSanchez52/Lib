/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:38:29 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:25 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double				ft_roundl(long double x)
{
	long long	nb;

	if (x < 0)
		x -= 0.4999999;
	else
		x += 0.4999999;
	nb = (long long)x;
	return ((long double)nb);
}

size_t					ft_longlen(long nb)
{
	size_t		len;

	len = 1;
	if (nb < 0)
	{
		nb = -1 * nb;
		len++;
	}
	while (nb / 10)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char					*ft_add_a_char(char *str, char c, int end)
{
	char			*tmp;

	if (!(tmp = ft_strnew(ft_strlen(str) + 1)))
		ft_print_error("Space adding problem");
	if (!end)
		tmp[0] = c;
	ft_strcat(tmp, str);
	free(str);
	str = tmp;
	if (end)
		str[ft_strlen(str)] = c;
	return (str);
}

unsigned long long		ft_ten_pow(int nb)
{
	static const unsigned long long pow[20] = {1,
		10,
		100,
		1000,
		10000,
		100000,
		1000000,
		10000000,
		100000000,
		1000000000,
		10000000000,
		100000000000,
		1000000000000,
		10000000000000,
		100000000000000,
		1000000000000000,
		10000000000000000,
		100000000000000000,
		1000000000000000000};

	return (pow[nb]);
}

char					*fill_with_zeros(char *str, int len)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	while (i < len)
	{
		str[i] = '0';
		i++;
	}
	str[len] = 0;
	return (str);
}
