/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_by_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 08:49:31 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:25 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				print_attributes(t_attributes *arg_att_list)
{
	ft_putendl("\tAttributes :");
	ft_putstr("\t\ttype is ");
	ft_putnbr(arg_att_list->type);
	ft_putstr("\n\t\tzero_filled state is ");
	ft_putnbr(arg_att_list->zero_filled);
	ft_putstr("\n\t\tleft_aligned state is ");
	ft_putnbr(arg_att_list->left_aligned);
	ft_putstr("\n\t\tplus state is ");
	ft_putnbr(arg_att_list->plus);
	ft_putstr("\n\t\tspace state is ");
	ft_putnbr(arg_att_list->space);
	ft_putstr("\n\t\tprefix state is ");
	ft_putnbr(arg_att_list->prefix);
	ft_putstr("\n\t\twidth is ");
	ft_putnbr(arg_att_list->width);
	ft_putstr("\n\t\tprecision state is ");
	ft_putnbr(arg_att_list->prec);
	ft_putstr("\n\t\tprecision is ");
	ft_putnbr(arg_att_list->precision);
	ft_putstr("\n\t\tconversion is ");
	ft_putstr(&arg_att_list->conversion);
	ft_putendl("");
}

/*
**	From attributes creates a string to return
*/

static inline char	*make_str_from(t_attributes *att_list)
{
	if (att_list->conversion == 'c' || att_list->conversion == 'C')
		return (ft_c_conv(att_list));
	if (att_list->conversion == 's')
		return (ft_s_conv(att_list));
	if (att_list->conversion == 'd' || att_list->conversion == 'i'
			|| att_list->conversion == 'D')
		return (ft_d_conv(att_list));
	if (att_list->conversion == 'u')
		return (ft_u_conv(att_list));
	if (att_list->conversion == 'o')
		return (ft_o_conv(att_list));
	if (att_list->conversion == 'x')
		return (ft_x_conv(att_list));
	if (att_list->conversion == 'X')
		return (ft_bigx_conv(att_list));
	if (att_list->conversion == 'f' || att_list->conversion == 'F')
		return (ft_f_conv(att_list));
	if (att_list->conversion == 'p')
		return (ft_p_conv(att_list));
	if (att_list->conversion == '%')
		return (ft_percent_conv(att_list));
	return ("(null)");
}

/*
**	Returns the corresponding str to the data given in arg_list
**	First parses format to know attributes and then uses it to make the good
**	string to return
*/

char				*replace_by_str(char *format, t_attributes *att_list)
{
	if (att_list->conversion == 'f')
		att_list->precision = 6;
	if (*format)
	{
		ft_find_options(format, att_list);
		ft_find_width(format, att_list);
		ft_find_precis(format, att_list);
		ft_find_type(format, att_list);
	}
	return (make_str_from(att_list));
}
