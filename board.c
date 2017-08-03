/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryukhyme <ryukhyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 21:36:51 by ryukhyme          #+#    #+#             */
/*   Updated: 2017/01/06 18:48:07 by ryukhyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		board_size(int size, int *input)
{
	int tetri_c;

	tetri_c = tetri_count(input);
	while (size * size < 4 * tetri_c)
		size++;
	return (size);
}

char	**create_pr_board(int size)
{
	int		col;
	int		row;
	char	**pr_board;

	row = 0;
	if (!(pr_board = (char **)malloc(sizeof(char *) * size + 1)))
		return (0);
	while (row < size)
	{
		if (!(pr_board[row] = (char *)malloc(sizeof(char) * size + 1)))
			return (0);
		col = 0;
		while (col < size)
		{
			pr_board[row][col] = '.';
			col++;
		}
		row++;
	}
	return (pr_board);
}

void	print_result(char ***pr_board, int size)
{
	int		col;
	int		row;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			write(1, &pr_board[0][row][col], 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int		tetri_count(int *input)
{
	int tetri_count;

	tetri_count = 0;
	while (input[tetri_count] != '\0')
		tetri_count++;
	return (tetri_count);
}

t_td	write_ctet(t_td tetri, int ntet, int let)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (g_coord[ntet][i] != '\0')
	{
		tetri.tet[c].c = (g_coord[ntet][i] - 48);
		tetri.tet[c].r = (g_coord[ntet][i + 1] - 48);
		i += 2;
		c++;
	}
	tetri.letter = (char)('A' + let);
	return (tetri);
}
