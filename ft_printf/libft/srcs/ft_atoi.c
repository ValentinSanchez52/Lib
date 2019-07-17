/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:50:32 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/16 19:07:59 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		res;
	int		state;

	res = 0;
	state = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			state = 1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res *= 10;
		res += *str - 48;
		str++;
	}
	if (state)
		res *= -1;
	return (res);
}
