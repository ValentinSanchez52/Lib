/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:14:54 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/15 14:15:31 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*tmp;
	t_list		*lst_bis;

	lst_bis = lst;
	while (lst_bis != NULL)
	{
		tmp = lst_bis->next;
		f(lst_bis);
		lst_bis = tmp;
	}
}
