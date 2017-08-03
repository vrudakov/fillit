/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryukhyme <ryukhyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:12:31 by ryukhyme          #+#    #+#             */
/*   Updated: 2017/01/06 18:49:52 by ryukhyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					is_reals(t_board wbr, t_coord ap, t_td ct, int *i)
{
	int k;
	int pos;

	k = 0;
	pos = 0;
	while (k < 4 && ap.r + ct.tet[k].r < wbr.size)
	{
		if (ap.c + ct.tet[k].c - ct.tet[0].c >= 0)
		{
			if (wbr.brd[ap.r + ct.tet[k].r][ap.c + ct.tet[k].c - ct.tet[0].c] ==
			'.')
				pos++;
		}
		k++;
	}
	if (pos == 4)
	{
		insert(wbr, ap, ct, i);
		return (0);
	}
	return (1);
}

static void			tabinit(int *tn, t_coord *av_pos, t_td **allt, int *m_input)
{
	allt[0] = create_str(m_input);
	av_pos->c = 0;
	av_pos->r = 0;
	*tn = 0;
}

static t_coord		nextrow(t_coord ap)
{
	t_coord tmp;

	tmp = ap;
	tmp.r++;
	tmp.c = -1;
	return (tmp);
}

int					solve_pros(t_board wboard, int *m_input)
{
	int			tn;
	t_coord		ap;
	t_td		*alltetri;

	tabinit(&tn, &ap, &alltetri, m_input);
	while (tn != wboard.ntetri)
	{
		ap = find_pos(wboard, ap);
		while (1 == is_reals(wboard, ap, alltetri[tn], &tn))
		{
			if (ap.c == wboard.size)
			{
				if (ap.r == (wboard.size - 1) && tn == 0)
					return (1);
				else if (ap.r == (wboard.size - 1))
					ap = rollback_s(&wboard, alltetri[tn - 1], &tn);
				else
					ap = nextrow(ap);
			}
			ap.c++;
		}
	}
	return (0);
}

void				slower(int *m_input)
{
	t_board		sboard;

	sboard.size = board_size(0, m_input);
	sboard.brd = create_pr_board(sboard.size);
	sboard.in_t = create_vr_coords();
	sboard.ntetri = tetri_count(m_input);
	coord();
	while (solve_pros(sboard, m_input) != 0)
	{
		sboard.size++;
		sboard.brd = create_pr_board(sboard.size);
		sboard.in_t = create_vr_coords();
	}
	print_result(&sboard.brd, sboard.size);
}
