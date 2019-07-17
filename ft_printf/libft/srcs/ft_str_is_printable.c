/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:54:08 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/12 17:59:29 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_str_is_printable(const char *str)
{
	while (*str)
	{
		if (!(ft_isgraph(*str) || *str == ' '))
			return (0);
		str++;
	}
	return (1);
}
