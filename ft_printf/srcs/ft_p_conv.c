/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 04:50:36 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:24 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline char			*ft_p_conv(t_attributes *att_list)
{
	char			*str;
	long long		nb;

	nb = va_arg(att_list->arg_list, long long);
	if (nb == 0)
		str = ft_strdup("0x0");
	else
	{
		str = ft_lltoa_base(nb, X_BASE);
		str = ft_add_a_prefix(str, 'x');
	}
	str = ft_make_str(str, att_list->width, att_list->left_aligned);
	if (att_list->zero_filled && !att_list->left_aligned)
		str = zero_filler(str, att_list);
	return (str);
}
