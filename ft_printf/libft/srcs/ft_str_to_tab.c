/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <vsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 17:00:40 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/14 06:24:43 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_print_str_tab(char **tab)
{
	size_t			tab_i;

	tab_i = -1;
	if (tab)
	{
		while (tab[++tab_i])
		{
			ft_putstr(YELLOW"line ");
			ft_putnbr((int)tab_i + 1);
			ft_putstr(" : "NRM);
			ft_putendl(tab[tab_i]);
		}
	}
}

void				free_str_tab(char **tab)
{
	size_t			i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab[i]);
	free(tab);
}

static size_t		ft_line_nb(const char *str)
{
	size_t			count;

	if (!str)
		return (0);
	count = 1;
	while (*str)
		if (*str++ == '\n')
			count++;
	return (count);
}

static size_t		ft_line_len(const char *str)
{
	size_t			str_len;

	str_len = 0;
	while (str[str_len] && str[str_len] != '\n')
		str_len++;
	return (str_len);
}

char				**ft_str_to_tab(const char *str)
{
	char			**tab;
	size_t			str_i;
	size_t			tab_i;
	size_t			str_len;
	size_t			nl_nb;

	if (!str)
		return (NULL);
	nl_nb = ft_line_nb(str);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * nl_nb)))
		ft_print_error("allocation failed in ft_str_to_tab");
	tab_i = -1;
	str_i = 0;
	while (str[str_i] && nl_nb > 0)
	{
		str_len = ft_line_len(&str[str_i]);
		if (!(tab[++tab_i] = ft_strsub(&str[str_i], 0, str_len + 1)))
			ft_print_error("allocation failed in ft_str_to_tab");
		str_i += str_len + 1;
		nl_nb--;
	}
	tab[++tab_i] = NULL;
	return (tab);
}
