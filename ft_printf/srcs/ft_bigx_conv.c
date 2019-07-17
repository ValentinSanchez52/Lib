/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigx_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 04:49:35 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/12 13:22:23 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline char			*ft_bigx_conv(t_attributes *att_list)
{
	return (ft_str_to_upper_case(ft_x_conv(att_list)));
}
