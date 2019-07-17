/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <vsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:22:08 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/10 13:22:08 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(char *str)
{
	char	*rev;
	int		i;
	int		j;

	i = ft_strlen(str) - 1;
	j = 0;
	rev = ft_strnew(ft_strlen(str));
	while (i >= 0)
	{
		rev[j] = str[i];
		i--;
		j++;
	}
	free(str);
	return (rev);
}
