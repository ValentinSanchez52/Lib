/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 00:52:56 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:24 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Summary of stdarg:
**
**	va_list sets a list of arguments ("...") and it's a type
**	va_start set the first argument after the one given a bit like open()
**	va_copy COPIES the current arg_list to an other one
**	va_arg returns the value with the good type
**	va_end frees the list whih is suposed to end like free() or close()
**	Globally stdarg macros work a bit like read function
*/

static inline int	null_char_printf(char *str)
{
	char		*tmp;
	char		*null_pos;
	int			printed_chars;

	tmp = str;
	printed_chars = 0;
	while ((null_pos = ft_strstr(str, "[pc0[")))
	{
		write(1, str, null_pos - str);
		printed_chars += null_pos - str;
		ft_putchar(0);
		printed_chars++;
		str += null_pos - str + 5;
	}
	ft_putstr(str);
	printed_chars += ft_strlen(str);
	free(tmp);
	return (printed_chars);
}

int					ft_printf(const char *restrict format, ...)
{
	char		*str;
	va_list		arg_list;
	int			len;

	if (!format)
		return (0);
	va_start(arg_list, format);
	if ((str = ft_vsprintf(format, arg_list)))
	{
		if (str && !ft_strstr(str, "[pc0["))
		{
			ft_putstr(str);
			len = ft_strlen(str);
			free(str);
			return (len);
		}
		else if (ft_strstr(str, "[pc0["))
			return (null_char_printf(str));
		else
			write(1, "(null)", 6);
	}
	va_end(arg_list);
	free(str);
	return (0);
}
