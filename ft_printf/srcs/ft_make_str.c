/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 04:14:22 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:24 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_make_str(char *str, int width, int left_aligned)
{
	char		*tmp;
	int			i;

	if ((int)ft_strlen(str) < width)
	{
		if (!(tmp = ft_strnew(width)))
			return (NULL);
		if (left_aligned)
			tmp = ft_strcpy(tmp, str);
		else
		{
			width -= ft_strlen(str);
			i = -1;
			while (++i < width)
				tmp[i] = ' ';
			ft_strcat(tmp, str);
		}
		free(str);
		str = tmp;
		i = -1;
		while (++i < width)
			if (str[i] == 0)
				str[i] = ' ';
	}
	return (str);
}
