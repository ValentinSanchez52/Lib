/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_str_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <vsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 05:57:55 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/14 06:12:53 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_get_arg_str_tab(char **arguments, size_t arg_nb)
{
	char			**str_tab;
	size_t			arg_i;

	if (!arg_nb)
		return (NULL);
	if (!(str_tab = (char **)ft_memalloc(sizeof(char *) * (arg_nb + 1))))
		ft_print_error("allocation failed in ft_get_arg_str_tab");
	arg_i = -1;
	while (++arg_i < arg_nb)
		if (!(str_tab[arg_i] = ft_strdup(arguments[arg_i])))
			ft_print_error("allocation failed in ft_get_arg_str_tab");
	str_tab[arg_nb] = NULL;
	return (str_tab);
}
