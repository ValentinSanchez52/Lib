/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 23:10:34 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/25 17:16:05 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_print_error(char *error_name)
{
	write(2, "Error\n", 7);
	if (PRINT_ERROR_ALLOWED)
		ft_putendl(error_name);
	exit(EXIT_FAILURE);
}
