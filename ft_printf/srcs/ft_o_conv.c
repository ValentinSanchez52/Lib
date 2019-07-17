/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 04:48:29 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:24 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline long long				get_nb(t_attributes *att_list)
{
	long long	nb;

	if (att_list->type == H)
		nb = (unsigned short)va_arg(att_list->arg_list, unsigned int);
	else if (att_list->type == HH)
		nb = (unsigned char)va_arg(att_list->arg_list, unsigned int);
	else if (att_list->type == L)
		nb = va_arg(att_list->arg_list, unsigned long);
	else if (att_list->type == LL)
		nb = va_arg(att_list->arg_list, unsigned long long);
	else
		nb = va_arg(att_list->arg_list, unsigned int);
	return (nb);
}

inline char							*ft_o_conv(t_attributes *att_list)
{
	char				*str;
	long long			nb;

	nb = get_nb(att_list);
	if (nb == 0 && att_list->prec && !att_list->precision)
	{
		if (!(str = ft_strdup("")))
			return (NULL);
	}
	else
	{
		str = ft_ulltoa_base(nb, O_BASE);
		str = diouxx_precision(str, att_list, ft_strlen(str));
	}
	if (att_list->prefix && ft_strchr("oxXf", att_list->conversion))
		str = ft_add_a_prefix(str, att_list->conversion);
	str = ft_make_str(str, att_list->width, att_list->left_aligned);
	if (att_list->zero_filled && !(att_list->left_aligned
				|| att_list->precision))
		str = zero_filler(str, att_list);
	return (str);
}
