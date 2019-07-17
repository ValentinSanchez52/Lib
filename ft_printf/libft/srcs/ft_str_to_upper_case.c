/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_upper_case.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <vsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:22:08 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:23:14 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_str_to_upper_case(char *str)
{
	char			*tmp;

	if (!str)
		return (str);
	tmp = str;
	while (*tmp)
	{
		if (ft_isalpha(*tmp) && ft_islower(*tmp))
			*tmp += 'A' - 'a';
		tmp++;
	}
	return (str);
}
