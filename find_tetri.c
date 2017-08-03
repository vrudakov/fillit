/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryukhyme <ryukhyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:07:31 by vrudakov          #+#    #+#             */
/*   Updated: 2017/01/06 18:17:57 by ryukhyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*g_pat[20];

void	patern(void)
{
	g_pat[0] = ".";
	g_pat[1] = "####";
	g_pat[2] = "#...#...#...#";
	g_pat[3] = "#...#...##";
	g_pat[4] = "###.#";
	g_pat[5] = "##...#...#";
	g_pat[6] = "#.###";
	g_pat[7] = "#...#..##";
	g_pat[8] = "###...#";
	g_pat[9] = "##..#...#";
	g_pat[10] = "#...###";
	g_pat[11] = "##..##";
	g_pat[12] = "#..###";
	g_pat[13] = "#...##..#";
	g_pat[14] = "###..#";
	g_pat[15] = "#..##...#";
	g_pat[16] = "##...##";
	g_pat[17] = "#..##..#";
	g_pat[18] = "##.##";
	g_pat[19] = "#...##...#";
}

char	**tabjoin(char **tab)
{
	int		j;
	int		i;
	int		k;
	char	**string;

	i = 1;
	j = 0;
	k = 0;
	while (tab[j] != NULL)
		j++;
	string = (char **)malloc(sizeof(char *) * (j / 4 + 1));
	if (!string)
		return (NULL);
	j = 0;
	while (tab[j] != NULL)
	{
		string[k] = ft_strdup(tab[j]);
		while (i <= j + 3)
			string[k] = ft_strjoin(string[k], tab[i++]);
		j = i;
		k++;
		i++;
	}
	string[k] = NULL;
	return (string);
}

int		*input_tets(char *str)
{
	int				i;
	int				n;
	char			**new;
	static int		input[26];

	i = 0;
	new = tabjoin(ft_strsplit(str, '\n'));
	trim(new);
	patern();
	while (new[i])
	{
		n = 1;
		while (n < 20)
		{
			if (!ft_strcmp(new[i], g_pat[n]))
			{
				input[i] = n;
				break ;
			}
			n++;
		}
		i++;
	}
	input[i] = '\0';
	return (input);
}

char	*get_patern(int i)
{
	char	*tetri;

	if (i == 6)
	{
		tetri = ft_strjoin("..", g_pat[i]);
		return (tetri);
	}
	if (i == 7 || i == 12 || i == 15 || i == 17 || i == 18)
	{
		tetri = ft_strjoin(".", g_pat[i]);
		return (tetri);
	}
	tetri = ft_strdup(g_pat[i]);
	return (tetri);
}

char	*s2a(char *s, int i)
{
	char	letter;
	int		j;

	j = -1;
	letter = (char)('A' + i);
	while (s[++j] != '\0')
	{
		if (s[j] == '#')
			s[j] = letter;
	}
	return (s);
}
