/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_attributes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 23:52:41 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:24 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_find_options(const char *format, t_attributes *att_list)
{
	if (ft_strstr(format, "-"))
		att_list->left_aligned = 1;
	if (ft_strstr(format, "+"))
		att_list->plus = 1;
	if (ft_strstr(format, " "))
		att_list->space = 1;
	if (ft_strstr(format, "#"))
		att_list->prefix = 1;
	while (*format && !ft_isdigit(*format))
		format++;
	if (*format == '0')
		att_list->zero_filled = 1;
}

void				ft_find_width(const char *format, t_attributes *att_list)
{
	while ((*format && !ft_isdigit(*format) && *format != '.')
			|| *format == '0')
		format++;
	if (*format && *format != '.')
		att_list->width = ft_atoi(format);
}

void				ft_find_precis(const char *format, t_attributes *att_list)
{
	while (*format && *format != '.')
		format++;
	if (*format == '.')
	{
		att_list->prec = 1;
		format++;
		if (ft_isdigit(*format))
			att_list->precision = ft_atoi(format);
	}
}

static inline void	ft_set_type(char *tmp, t_attributes *att_list)
{
	int				i;
	int				count;

	i = -1;
	count = 0;
	while (tmp[++i])
		if (tmp[i] == 'h')
			count++;
		else if (tmp[i] == 'l')
			count--;
	if (count > 0)
		att_list->type = (count % 2) ? H : HH;
	if (count < 0)
		att_list->type = (-count % 2) ? L : LL;
}

void				ft_find_type(const char *format, t_attributes *att_list)
{
	char			*tmp;

	if (!(tmp = ft_strnew(ft_strlen(format))))
		return ;
	while (*format)
	{
		if (format == ft_strstr(format, "h"))
			ft_strcat(tmp, "h");
		if (format == ft_strstr(format, "l"))
			ft_strcat(tmp, "l");
		if (format == ft_strstr(format, "L"))
		{
			ft_strcat(tmp, "ll");
			format++;
		}
		else
			format++;
	}
	ft_set_type(tmp, att_list);
	free(tmp);
}
