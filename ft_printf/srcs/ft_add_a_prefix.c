/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_a_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:54:26 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/25 16:05:33 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline char	*ft_add_a_prefix(char *str, char conversion)
{
	char			*tmp;

	if (!(tmp = ft_strnew(ft_strlen(str) + 1)))
		ft_print_error("allocation failed in ft_add_a_prefix");
	if (conversion == 'f')
		ft_strcat(tmp, ".");
	else if (conversion == 'o' && str[0] != '0')
		ft_strcat(tmp, "0");
	else if (ft_strchr("xX", conversion))
	{
		free(tmp);
		if (!(tmp = ft_strnew(ft_strlen(str) + 2)))
			ft_print_error("allocation failed in ft_add_a_prefix");
		ft_strcat(tmp, "0");
		ft_strcat(tmp, (conversion == 'x') ? "x" : "X");
	}
	ft_strcat(tmp, str);
	free(str);
	str = tmp;
	return (str);
}
