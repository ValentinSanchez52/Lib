/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 04:48:59 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:25 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline long long	get_nb(t_attributes *att_list)
{
	long long			nb;

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

static inline char		*width_zero_prefix_x_case(char *str,
		t_attributes *att_list)
{
	char				*tmp;
	int					str_len;
	int					i;
	int					end_thick;
	size_t				width;

	width = att_list->width;
	str_len = width > 2 + ft_strlen(str) ? width : 2 + ft_strlen(str);
	if ((tmp = ft_strnew(str_len)))
	{
		tmp = ft_strcat(tmp, "0x");
		i = 1;
		end_thick = str_len - ft_strlen(str);
		while (++i < end_thick)
			tmp[i] = '0';
		tmp = ft_strcat(tmp, str);
		free(str);
		return (tmp);
	}
	else
		return (NULL);
}

inline char				*ft_x_conv(t_attributes *att_list)
{
	char				*str;
	long long			nb;

	nb = get_nb(att_list);
	if (nb == 0 && att_list->prec && !att_list->precision)
	{
		if (!att_list->width)
			return (ft_strdup(""));
		else if (!(str = ft_strdup("")))
			return (NULL);
	}
	else if (nb == 0)
		return (ft_strdup("0"));
	str = ft_ulltoa_base(nb, X_BASE);
	str = diouxx_precision(str, att_list, ft_strlen(str));
	if (att_list->width && att_list->zero_filled && att_list->prefix
			&& !att_list->left_aligned && !att_list->plus)
		return (width_zero_prefix_x_case(str, att_list));
	if (att_list->prefix && !(!nb && att_list->prec && !att_list->precision))
		str = ft_add_a_prefix(str, att_list->conversion);
	str = ft_make_str(str, att_list->width, att_list->left_aligned);
	if (att_list->zero_filled && !att_list->left_aligned
			&& !att_list->precision)
		str = zero_filler(str, att_list);
	return (str);
}
