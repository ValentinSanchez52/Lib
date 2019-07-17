/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:54:35 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/12 17:54:49 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_str_is_uppercase(const char *str)
{
	while (*str)
		if (!(ft_isupper(*str++)))
			return (0);
	return (1);
}
