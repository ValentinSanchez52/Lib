/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_a_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:17:40 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/25 16:04:40 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline char	*ft_add_a_plus(char *str)
{
	char			*tmp;

	if (str[0] == '-' || str[0] == '+')
		return (str);
	if (!(tmp = ft_strnew(ft_strlen(str) + 1)))
		ft_print_error("strnew failed in ft_add_a_plus");
	ft_strcat(tmp, "+");
	ft_strcat(tmp, str);
	free(str);
	str = tmp;
	return (str);
}

inline char	*ft_add_a_minus(char *str)
{
	char			*tmp;

	if (str[0] == '-' || str[0] == '+')
		return (str);
	if (!(tmp = ft_strnew(ft_strlen(str) + 1)))
		ft_print_error("strnew failed in ft_add_a_minus");
	ft_strcat(tmp, "-");
	ft_strcat(tmp, str);
	free(str);
	str = tmp;
	return (str);
}
