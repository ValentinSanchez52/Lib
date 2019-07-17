/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:45:44 by vsanchez          #+#    #+#             */
/*   Updated: 2019/05/14 08:23:42 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_words_nb(const char *s, char c)
{
	int		nb;

	nb = 0;
	while (*s)
	{
		if (*s != c)
		{
			nb++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (nb);
}

static int		ft_word_len(const char *s, char c)
{
	int			len;

	len = 0;
	if (*s == c)
		return (0);
	while (*s != 0 && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		words_nb;
	int		word_len;
	int		i;

	if (!s)
		return (NULL);
	words_nb = ft_words_nb(s, c);
	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (words_nb + 1))))
		return (NULL);
	while (words_nb > 0 && *s)
	{
		while (ft_word_len(s, c) == 0)
			s++;
		word_len = ft_word_len(s, c);
		if (!(tab[i] = ft_strnew(word_len)))
			return (NULL);
		ft_strncpy(tab[i], s, word_len);
		s += word_len;
		i++;
		words_nb--;
	}
	tab[i] = NULL;
	return (tab);
}
