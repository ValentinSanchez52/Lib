/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 04:34:03 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:23 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline char	*ft_make_c_str(char *str, int width, int left_aligned)
{
	char			*tmp;
	int				i;

	if ((int)ft_strlen(str) < width + 5)
	{
		if (!(tmp = ft_strnew(width + 5)))
			return (NULL);
		if (left_aligned)
			tmp = ft_strcpy(tmp, str);
		else
		{
			width -= ft_strlen(str) - 4;
			i = -1;
			while (++i < width)
				tmp[i] = ' ';
			ft_strcat(tmp, str);
		}
		free(str);
		str = tmp;
		i = -1;
		while (++i < width + 5)
			if (str[i] == 0)
				str[i] = ' ';
	}
	return (str);
}

inline char			*ft_c_conv(t_attributes *att_list)
{
	char			*str;

	if (!(str = ft_strnew(1)))
		return (NULL);
	*str = (char)va_arg(att_list->arg_list, int);
	if (*str == 0)
	{
		free(str);
		str = ft_strdup("[pc0[");
		str = ft_make_c_str(str, att_list->width, att_list->left_aligned);
		att_list->nb_null_param++;
	}
	else
	{
		str = ft_make_str(str, att_list->width, att_list->left_aligned);
		if (att_list->zero_filled && !att_list->left_aligned)
			str = zero_filler(str, att_list);
	}
	return (str);
}
