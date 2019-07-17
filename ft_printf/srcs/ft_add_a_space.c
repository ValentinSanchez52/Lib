/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_a_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:18:15 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/25 16:06:22 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline char	*ft_add_a_space(char *str)
{
	char			*tmp;

	if (str[0] == '-' || str[0] == '+')
		return (str);
	if (!(tmp = ft_strnew(ft_strlen(str) + 1)))
		ft_print_error("allocation failed in ft_add_a_space");
	ft_strcat(tmp, " ");
	ft_strcat(tmp, str);
	free(str);
	str = tmp;
	return (str);
}
