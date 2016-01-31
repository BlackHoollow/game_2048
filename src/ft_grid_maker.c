/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_maker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 21:27:58 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/31 21:28:23 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		ft_make_pat(int col, int row, int rpos)
{
	int		citer;
	int		riter;
	int		cpos;

	riter = row / 4;
	citer = col / 4;
	while (riter-- > 0)
	{
		cpos = 0;
		mvaddch(rpos, cpos++, '|');
		while (cpos < col)
		{
			citer = (col / 4);
			while (citer-- > 0 && cpos < col)
				mvaddch(rpos, cpos++, ' ');
			mvaddch(rpos, cpos++, '|');
		}
		rpos++;
	}
	rpos--;
	return (rpos);
}

int				ft_draw_grid(int col, int row)
{
	int		cs;
	int		rs;
	int		ss;

	ss = 0;
	rs = 0;
	if (row < 25 || col < 61)
		return (-1);
	while (ss++ < 4)
	{
		cs = 0;
		mvaddch(rs, cs++, '|');
		while (cs < col)
			mvaddch(rs, cs++, '-');
		mvaddch(rs++, cs, '|');
		rs = ft_make_pat(col, row, rs);
	}
	cs = 0;
	mvaddch(rs, cs++, '|');
	while (cs < col)
		mvaddch(rs, cs++, '-');
	mvaddch(rs++, cs, '|');
	refresh();
	return (0);
}
