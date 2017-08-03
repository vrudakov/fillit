/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryukhyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:51:54 by ryukhyme          #+#    #+#             */
/*   Updated: 2016/12/01 13:24:43 by ryukhyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_quawords(char *str, char c)
{
	int	i;
	int	qua;

	i = 0;
	qua = 0;
	while (str[i] != '\0')
	{
		if ((i != 0 && str[i] != c && str[i - 1] == c) || (str[0] != c))
			qua++;
		i++;
	}
	return (qua);
}

static void			ft_split(char **tab, char const *s, char c)
{
	int		l;
	int		i;
	int		j;

	i = 0;
	j = 0;
	l = 0;
	while (s[i])
	{
		while ((s[i + l] != '\0') && (s[i + l] != c))
			l++;
		if (l != 0)
		{
			tab[j++] = ft_strsub(s, i, l);
			i = i + l;
		}
		else
			i = i + 1;
		l = 0;
	}
	tab[j] = NULL;
}

char				**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * ((ft_quawords((char *)s, c) + 1)));
	if (!tab)
		return (NULL);
	ft_split(tab, (char *)s, c);
	return (tab);
}
