/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <vsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:22:08 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/10 13:22:08 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putaddr(void const *p)
{
	unsigned long	adr;
	char const		*base;
	char			res[9];
	int				i;

	adr = (unsigned long)p;
	base = "0123456789abcdef";
	i = 8;
	while ((adr / 16) > 0 || i >= 8)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	ft_putstr("0x");
	while (i < 9)
	{
		ft_putchar(res[i]);
		i++;
	}
}
