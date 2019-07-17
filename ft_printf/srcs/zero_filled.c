/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_filled.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 04:11:41 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:25 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*zero_filler(char *str, t_attributes *att_list)
{
	int					i;

	i = -1;
	i = (att_list->space && !att_list->plus
			&& !ft_strchr("scxXp", att_list->conversion)) ? 0 : -1;
	if (str)
	{
		if (!ft_strchr("scxXp", att_list->conversion) && ft_strchr(str, '-'))
			str[++i] = '-';
		if (!ft_strchr("scxXp", att_list->conversion) && ft_strchr(str, '+'))
			str[++i] = '+';
		while (str[++i])
			if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
				str[i] = '0';
	}
	return (str);
}

char					*f_zero_filler(char *str, t_attributes *att_list)
{
	int					sign;
	int					i;
	int					len;
	char				*tmp;

	sign = 0;
	i = att_list->width;
	len = ft_strlen(str);
	if (len >= att_list->width || !(tmp = ft_strnew(att_list->width)))
		return (str);
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
	{
		sign = 1;
		tmp[0] = str[0];
	}
	while (i-- > len)
		tmp = ft_strcat(tmp, "0");
	tmp = ft_strcat(tmp, str + sign);
	free(str);
	str = tmp;
	return (str);
}
