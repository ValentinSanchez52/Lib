/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 10:39:39 by vsanchez          #+#    #+#             */
/*   Updated: 2019/01/17 08:46:51 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_realloc(char *buff, size_t size, size_t n)
{
	char		*tmp;

	if (!(tmp = (char *)ft_memalloc(size + n + 1)))
		return (NULL);
	if (buff)
	{
		ft_strncpy(tmp, buff, size);
		free(buff);
	}
	return (tmp);
}
