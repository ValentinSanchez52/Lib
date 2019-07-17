/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:41:00 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/14 14:56:23 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	char	*mem;

	if (!(mem = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
