/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 01:58:03 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:24 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int			alone_percent(const char *format)
{
	int				i;

	i = 1;
	while (!ft_strchr("DCFfdiouxXscp%", format[i]))
		i++;
	if (!format[i])
		return (1);
	else
		return (0);
}

inline char			*ft_percent_conv(t_attributes *att_list)
{
	char			*str;

	str = ft_strdup("%");
	str = ft_make_str(str, att_list->width, att_list->left_aligned);
	if (att_list->zero_filled && !att_list->left_aligned && !att_list->prec)
		str = zero_filler(str, att_list);
	return (str);
}
