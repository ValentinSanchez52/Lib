/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <vsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:22:08 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/25 17:12:50 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **lst, t_list *new)
{
	t_list	*tmp;

	new->next = NULL;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		tmp = *lst;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}
