/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:21:21 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/15 14:57:24 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list			*ft_lstnew(const void *content, size_t content_size)
{
	t_list		*lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list *))))
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else if (!(lst->content = ft_memalloc(content_size)))
		return (NULL);
	else
	{
		lst->content = ft_strdup(content);
		lst->content_size = content_size;
	}
	lst->next = NULL;
	return (lst);
}
