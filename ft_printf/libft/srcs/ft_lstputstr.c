/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstputstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <vsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:22:08 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/10 13:22:08 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstputstr(t_list *alst)
{
	while (alst)
	{
		ft_putstr((*alst).content);
		ft_putstr("\n");
		alst = (*alst).next;
	}
}
