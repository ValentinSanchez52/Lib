/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 04:50:08 by vsanchez          #+#    #+#             */
/*   Updated: 2019/06/07 09:13:18 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

static char					*round_str_nb(char *str)
{
	int			len;
	int			i;
	int			out;

	len = ft_strlen(str);
	i = 0;
	out = 0;
	if (ft_isdigit(str[len - 1]) == 1 && str[len - 1] != '9')
		return (str);
	str = ft_strrev(str);
	while (str[i] && out == 0)
	{
		if (str[i] == '9')
			str[i] = '0';
		else if (ft_isdigit(str[i]) == 1)
		{
			str[i] += 1;
			out = 1;
		}
		i++;
	}
	if (out == 0)
		str = ft_add_a_char(str, '1', 0);
	str = ft_strrev(str);
	return (str);
}

static char					*ft_is_inf_nan(long double f)
{
	if (f == FP_INFINITE)
		return (ft_strdup("inf"));
	else if (f == FP_NAN)
		return (ft_strdup("nan"));
	else
		return (NULL);
}

static inline char			*ft_ftoa_body(char *str, long double f, int prec)
{
	int						i;
	char					n;
	char					*dec_part;
	unsigned long long		power;

	power = 1;
	while (power * 10 <= f)
		power *= 10;
	i = ft_strlen(str);
	while (power >= 1)
	{
		n = (char)(f / power);
		f -= n * power;
		power /= 10;
		str[i] = n + '0';
		i++;
	}
	power = ft_ten_pow(prec);
	if (prec == 0)
		return (str);
	str = ft_strcat(str, ".");
	dec_part = ft_ltoa_base(ft_roundl(f * power), 10);
	str = ft_strcat(str, dec_part);
	free(dec_part);
	return (str);
}

static inline char			*ft_ftoa(long double f, int prec)
{
	char			*str;
	int				len;
	int				neg;

	neg = 1;
	if ((str = ft_is_inf_nan(f)))
		return (str);
	if (f < 0 || (1.0 / f == FP_INFINITE))
	{
		neg = -1;
		f = -f;
	}
	len = ft_longlen(f) + prec;
	if (prec != 0)
		len += 1;
	if (prec == 0)
		f = ft_roundl(f);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str = ft_ftoa_body(str, f, prec);
	fill_with_zeros(str, len);
	str = round_str_nb(str);
	if (neg == -1)
		str = ft_add_a_minus(str);
	return (str);
}

inline char					*ft_f_conv(t_attributes *att_list)
{
	char			*f;

	if (att_list->type == 0)
		f = ft_ftoa(va_arg(att_list->arg_list, double), att_list->precision);
	if (att_list->type == L)
		f = ft_ftoa(va_arg(att_list->arg_list, double), att_list->precision);
	else if (att_list->type == LL)
		f = ft_ftoa(va_arg(att_list->arg_list, long double),
				att_list->precision);
	if (att_list->prefix && att_list->prec && !att_list->precision)
		f = ft_add_a_char(f, '.', 1);
	if (att_list->plus)
		f = ft_add_a_plus(f);
	else if (att_list->space)
		f = ft_add_a_space(f);
	if (att_list->zero_filled && !att_list->left_aligned)
		f = f_zero_filler(f, att_list);
	f = ft_make_str(f, att_list->width, att_list->left_aligned);
	return (f);
}
