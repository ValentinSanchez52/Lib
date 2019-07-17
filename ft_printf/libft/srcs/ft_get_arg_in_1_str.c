/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_in_1_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <vsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 06:33:52 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/14 14:59:53 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_get_arg_in_1_str(char **arguments, size_t arg_nb)
{
	char			*str;
	size_t			arg_i;

	if (!arg_nb)
		return (NULL);
	if (!(str = ft_strdup(arguments[0])))
		ft_print_error("allocation failed in ft_get_arg_in_1_str");
	arg_i = 0;
	while (++arg_i < arg_nb)
	{
		if (!(str = ft_realloc(str, ft_strlen(str),
						1 + ft_strlen(arguments[arg_i]))))
			ft_print_error("allocation failed in ft_get_arg_in_1_str");
		ft_strcat(str, " ");
		ft_strcat(str, arguments[arg_i]);
	}
	return (str);
}
