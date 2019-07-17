/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:52:47 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/12 17:53:23 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_str_is_lowercase(const char *str)
{
	while (*str)
		if (!(ft_islower(*str++)))
			return (0);
	return (1);
}
