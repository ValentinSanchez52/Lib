/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:53:57 by vsanchez          #+#    #+#             */
/*   Updated: 2018/11/15 14:18:22 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;
	t_list		*alst_bis;

	alst_bis = *alst;
	while (alst_bis != NULL)
	{
		tmp = alst_bis->next;
		ft_lstdelone(&alst_bis, del);
		alst_bis = tmp;
	}
	*alst = NULL;
}
