/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:52:11 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:25 by vsanchez         ###   ########.fr       */
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

static t_attributes	*attributes_init(t_attributes *arg_att_list)
{
	if (!arg_att_list && !(arg_att_list = ft_memalloc(sizeof(t_attributes))))
		return (NULL);
	arg_att_list->type = 0;
	arg_att_list->width = 0;
	arg_att_list->prec = 0;
	arg_att_list->precision = 0;
	arg_att_list->zero_filled = 0;
	arg_att_list->left_aligned = 0;
	arg_att_list->plus = 0;
	arg_att_list->space = 0;
	arg_att_list->prefix = 0;
	arg_att_list->nb_null_param = 0;
	return (arg_att_list);
}

/*
**	Concatenates to str until the next '%' and returns how many chars to pass
**	Input is "%%" or "...%" so it checks from the second char and always write
**	the first one so "%%" -> "%" and "...%" -> "..."
**	If input is "%..." then Input is "%%..." thanks to ft_vsprintf
**	Then it returns 2 if Input is "%..." and the len of "..." if it's "...%"
*/

static inline int	ft_putstr_to_flag(const char *format, char **str)
{
	int			i;
	char		*to_cat;
	char		*tmp;

	i = 1;
	while (format[i] && format[i] != '%')
		i++;
	if (!(to_cat = ft_strsub(format, 0, i)))
		return (0);
	if (!(tmp = ft_realloc(*str, ft_strlen(*str), ft_strlen(to_cat))))
		ft_print_error("realloc ft_putstr_to_flag failed");
	if (to_cat)
		*str = ft_strcat(tmp, to_cat);
	i = ft_strlen(to_cat);
	free(to_cat);
	return (format[0] == '%' ? 2 : i);
}

/*
**	Concatenates to str a transformed data value in ASCII
**	It returns how many chars are describing the data value
*/

static inline int	format_parser(const char *format,
		t_attributes *arg_att_list, char **str)
{
	int				i;
	char			*to_cat;
	char			*tmp;
	char			*tmp2;

	if (alone_percent(format))
		return (1);
	i = 1;
	while (!ft_strchr("DCFfdiouxXscp%", format[i]))
		i++;
	arg_att_list->conversion = format[i];
	tmp2 = ft_strsub(format, 1, i - 1);
	to_cat = replace_by_str(tmp2, arg_att_list);
	if (!(tmp = ft_realloc(*str, ft_strlen(*str), ft_strlen(to_cat))))
		ft_print_error("realloc format_parser failed");
	if (to_cat)
		*str = ft_strcat(tmp, to_cat);
	free(to_cat);
	free(tmp2);
	return (i + 1);
}

/*
**	Returns a string made of text and/or data values transformed in ASCII
**	If we find a '%' and if there is no '%' following the first one then
**	format_parser is called else ft_putstr_to_flag is called
*/

char				*ft_vsprintf(const char *restrict format, va_list list)
{
	t_attributes	*att_list;
	char			*str;

	att_list = attributes_init(NULL);
	att_list->current_str = &str;
	va_copy(att_list->arg_list, list);
	if (!(str = ft_strnew(0)))
		return (NULL);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			att_list = attributes_init(att_list);
			format += format_parser(format, att_list, &str);
		}
		else
			format += ft_putstr_to_flag(format, &str);
	}
	va_end(att_list->arg_list);
	free(att_list);
	return (str);
}
