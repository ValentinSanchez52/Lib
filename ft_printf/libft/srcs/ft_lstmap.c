/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:15:43 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/16 18:59:57 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*map_lst;
	t_list		*lst_bis;

	if (lst == NULL)
		return (NULL);
	lst_bis = f(lst);
	map_lst = lst_bis;
	while (lst->next)
	{
		lst = lst->next;
		if (!(lst_bis->next = f(lst)))
		{
			free(lst_bis->next);
			return (NULL);
		}
		lst_bis = lst_bis->next;
	}
	return (map_lst);
}
