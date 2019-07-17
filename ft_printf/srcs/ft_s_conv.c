/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 04:46:38 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:25 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline char		*s_precision(char *str, int precision, int str_len)
{
	char				*tmp;

	if (str_len > precision)
		if ((tmp = ft_strnew(precision)))
		{
			tmp = ft_strncpy(tmp, str, precision);
			free(str);
			str = tmp;
		}
	return (str);
}

inline char				*ft_s_conv(t_attributes *att_list)
{
	char				*str;

	if (!(str = va_arg(att_list->arg_list, char *)))
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	if (att_list->prec)
		str = s_precision(str, att_list->precision, ft_strlen(str));
	str = ft_make_str(str, att_list->width, att_list->left_aligned);
	if (att_list->zero_filled && !att_list->left_aligned)
		str = zero_filler(str, att_list);
	return (str);
}
