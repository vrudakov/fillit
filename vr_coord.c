/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vr_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryukhyme <ryukhyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 21:50:42 by ryukhyme          #+#    #+#             */
/*   Updated: 2017/01/06 18:46:58 by ryukhyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coord		*create_vr_coords(void)
{
	int		i;
	t_coord *vr_coords;

	i = 0;
	vr_coords = (t_coord*)malloc(sizeof(t_coord) * 26);
	while (i < 26)
	{
		(vr_coords[i]).c = 0;
		(vr_coords[i]).r = 0;
		i++;
	}
	return (vr_coords);
}

t_coord		rollback_s(t_board *wboard, t_td ct, int *i)
{
	t_coord	res;
	int		n;

	n = *i;
	if (*i == 0)
	{
		write(1, "error\n", 6);
		exit(EXIT_FAILURE);
	}
	n = n - 1;
	res = wboard[0].in_t[n];
	wboard[0].in_t[n].c = 0;
	wboard[0].in_t[n].r = 0;
	wboard[0].brd[res.r + ct.tet[0].r][res.c + ct.tet[0].c - ct.tet[0].c] = '.';
	wboard[0].brd[res.r + ct.tet[1].r][res.c + ct.tet[1].c - ct.tet[0].c] = '.';
	wboard[0].brd[res.r + ct.tet[2].r][res.c + ct.tet[2].c - ct.tet[0].c] = '.';
	wboard[0].brd[res.r + ct.tet[3].r][res.c + ct.tet[3].c - ct.tet[0].c] = '.';
	*i -= 1;
	return (res);
}

void		insert(t_board wbrd, t_coord ap, t_td ct, int *i)
{
	wbrd.brd[ap.r + ct.tet[0].r][ap.c + ct.tet[0].c - ct.tet[0].c] = ct.letter;
	wbrd.brd[ap.r + ct.tet[1].r][ap.c + ct.tet[1].c - ct.tet[0].c] = ct.letter;
	wbrd.brd[ap.r + ct.tet[2].r][ap.c + ct.tet[2].c - ct.tet[0].c] = ct.letter;
	wbrd.brd[ap.r + ct.tet[3].r][ap.c + ct.tet[3].c - ct.tet[0].c] = ct.letter;
	wbrd.in_t[*i].r = ap.r;
	wbrd.in_t[*i].c = ap.c;
	*i += 1;
}

t_td		*create_str(int *input)
{
	int		i;
	t_td	*inputtetri;
	int		term;

	i = 0;
	term = tetri_count(input);
	inputtetri = (t_td*)malloc(sizeof(t_td) * 26);
	while (term)
	{
		inputtetri[i] = write_ctet(inputtetri[i], input[i], i);
		i++;
		term--;
	}
	return (inputtetri);
}

t_coord		find_pos(t_board wboard, t_coord in_pos)
{
	int		col;
	int		row;
	t_coord av_pos;

	row = -1;
	av_pos = in_pos;
	col = 0;
	while (++row < wboard.size)
	{
		col = -1;
		while (++col < wboard.size)
		{
			if (wboard.brd[row][col] == '.')
			{
				av_pos.r = row;
				av_pos.c = col;
				return (av_pos);
			}
		}
		col = 0;
	}
	return (av_pos);
}
