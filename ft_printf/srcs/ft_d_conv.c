/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 04:47:16 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:23 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline char			*diouxx_precision(char *str, t_attributes *att_list,
		int len)
{
	char		*tmp;
	int			neg;

	neg = 0;
	if (len <= att_list->precision
			&& (tmp = ft_strnew(att_list->precision += (str[0]
						== '-' ? 1 : 0))))
	{
		if (str[0] == '-' && (neg = 1))
			tmp[0] = *str++;
		while (len++ < att_list->precision)
			ft_strcat(tmp, "0");
		ft_strcat(tmp, str);
		free(str - neg);
		str = tmp;
	}
	else if (ft_strchr("dxX", att_list->conversion) && *str == '0')
		str[0] = 0;
	return (str);
}

inline char			*ft_d_conv(t_attributes *att_list)
{
	char			*str;

	if (att_list->type == H)
		str = ft_itoa_base((short)va_arg(att_list->arg_list, int), D_BASE);
	else if (att_list->type == HH)
		str = ft_itoa_base((char)va_arg(att_list->arg_list, int), D_BASE);
	else if (att_list->type == L)
		str = ft_ltoa_base(va_arg(att_list->arg_list, long), D_BASE);
	else if (att_list->type == LL)
		str = ft_lltoa_base(va_arg(att_list->arg_list, long long), D_BASE);
	else
		str = ft_itoa((int)va_arg(att_list->arg_list, int));
	if (att_list->prec)
		str = diouxx_precision(str, att_list, ft_strlen(str));
	if (att_list->prefix && ft_strchr("oxXf", att_list->conversion))
		str = ft_add_a_prefix(str, att_list->conversion);
	else if (att_list->plus)
		str = ft_add_a_plus(str);
	else if (att_list->space)
		str = ft_add_a_space(str);
	str = ft_make_str(str, att_list->width, att_list->left_aligned);
	if (att_list->zero_filled && !att_list->left_aligned && !att_list->prec)
		str = zero_filler(str, att_list);
	return (str);
}
