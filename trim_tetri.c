/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:32:32 by vrudakov          #+#    #+#             */
/*   Updated: 2016/12/27 20:06:59 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_t(char *str)
{
	int	count_t;

	count_t = ((int)ft_strlen(str) + 1) / 21;
	return (count_t);
}

char	*trim_dnl(char const *s)
{
	size_t	i;
	char	*fresh;
	size_t	i2;
	size_t	j;

	i = 0;
	i2 = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	while ((s[i] == '.') || (s[i] == '\n') || s[i] == '\0')
	{
		if (s[i] == '\0')
			return (ft_strdup(""));
		i++;
	}
	while ((s[j - 1] == '.') || (s[j - 1] == '\n'))
	{
		j--;
		i2++;
	}
	fresh = ft_strsub(s, i, ft_strlen(s) - i2 - i);
	return (fresh);
}

void	trim(char **arr)
{
	int n;

	n = -1;
	while (arr[++n])
		arr[n] = trim_dnl(arr[n]);
}

char	***tetri_arr(char *str)
{
	char	***arr_t;
	int		n;
	int		row;
	int		tet;

	tet = 0;
	n = count_t(str);
	arr_t = (char***)malloc(sizeof(char***) * (n + 1));
	arr_t[n] = NULL;
	while (n)
	{
		arr_t[tet] = (char**)malloc(sizeof(char**) * 5);
		arr_t[tet][4] = NULL;
		row = -1;
		while (++row < 4)
		{
			arr_t[tet][row] = (char*)malloc(sizeof(char*) * 5);
			ft_strncpy(arr_t[tet][row], str, 4);
			str += (str[5]) ? 5 : 0;
		}
		n--;
		tet++;
		str++;
	}
	return (arr_t);
}
