/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_of_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryukhyme <ryukhyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:25:42 by vrudakov          #+#    #+#             */
/*   Updated: 2017/01/06 18:37:24 by ryukhyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	sqr_valid(char *str)
{
	int		i;
	int		misc;
	int		h;

	misc = 0;
	i = -1;
	h = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '\n')
			h++;
		else
			misc++;
		if (h == 4)
		{
			if (misc / 4 != 4)
			{
				write(1, "error\n", 6);
				exit(EXIT_FAILURE);
			}
			misc = 0;
			h = 0;
			i++;
		}
	}
}

int		val_nl(char *str)
{
	int		nl;
	int		i;
	size_t	len;

	nl = 0;
	i = 0;
	len = ft_strlen(str);
	if ((str[len - 1] != '\n') || ((len + 1) % 21 != 0))
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			nl++;
		i++;
	}
	if ((ft_strlen(str) + 1) * 5 / 21 != (nl + 1))
		return (1);
	return (0);
}

int		ft_val_str(char *str)
{
	int		diez;
	int		dots;
	int		len;
	int		i;

	diez = 0;
	i = -1;
	dots = 0;
	len = (int)ft_strlen(str);
	if ((len + 1) % 21 != 0)
		return (1);
	while (++i <= len)
	{
		if (*str == '#')
			diez++;
		if (*str == '.')
			dots++;
		str++;
	}
	if (diez != (len + 1) * 4 / 21 || ((len + 1) * 12 / 21 != (dots)))
		return (1);
	return (0);
}

int		check_conect(char **arr)
{
	int x;
	int y;
	int count;

	count = 0;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (arr[y][x] == '#' && arr[y][x + 1] == '#')
				count++;
			if (((y + 1) < 4 && arr[y][x] == '#' && arr[y + 1][x] == '#'))
				count++;
		}
	}
	if (count < 3)
		return (0);
	return (1);
}

int		connection(char ***aarr)
{
	int n;

	n = -1;
	while (aarr[++n])
	{
		if (!check_conect(aarr[n]))
			return (1);
	}
	return (0);
}
