/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 21:18:11 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/31 21:34:07 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	ft_check_move(int ***grid)
{
	int		x;
	int		y;

	x = 1;
	while ((*grid)[x][1] != -1)
	{
		y = 1;
		while ((*grid)[x][y] != -1)
		{
			if ((*grid)[x - 1][y] == (*grid)[x][y] || (*grid)[x][y] ==
					(*grid)[x][y + 1] || (*grid)[x][y] == (*grid)[x][y - 1]
					|| (*grid)[x][y] == (*grid)[x + 1][y])
				return (0);
			y++;
		}
		x++;
	}
	return (-1);
}

int			ft_check(int ***grid)
{
	int		x;
	int		y;
	t_const win;

	win = WIN_VALUE;
	x = 1;
	while ((*grid)[x][1] != -1)
	{
		y = 1;
		while ((*grid)[x][y] != -1 && (*grid)[x][y] != (int)win)
			y++;
		if ((*grid)[x][y] == (int)win)
			return (1);
		x++;
	}
	return (ft_check_move(grid));
}

static void		ft_end_game(int index)
{
	clear();
	if (index == 1)
		mvprintw(0, 0, "YOU WIN!\nDOUBLE CLICK ENTER TO QUIT\n");
	else if (index == -1)
		mvprintw(0, 0, "YOU LOOSE!\nDOUBLE CLICK ENTER TO QUIT\n");
	refresh();
	while (getch() != 10)
	{
		if (index == 1)
			mvprintw(0, 0, "YOU WIN!\nDOUBLE CLICK ENTER TO QUIT\n");
		else if (index == -1)
			mvprintw(0, 0, "YOU LOOSE!\nDOUBLE CLICK ENTER TO QUIT\n");
		refresh();
	}
}

static void		ft_print_grid(int **grid, int x, int y)
{
	int		hy;
	int		hx;

	getmaxyx(stdscr, y, x);
	hy = (y / 4) / 2;
	hx = (x / 4) / 2;
	mvprintw(hy, hx, "%d", grid[0][0]);
	mvprintw(hy, (x / 4) + hx, "%d", grid[0][1]);
	mvprintw(hy, (x / 2) + hx, "%d", grid[0][2]);
	mvprintw(hy, (x - hx), "%d", grid[0][3]);
	mvprintw(hy * 3, hx, "%d", grid[1][0]);
	mvprintw(hy * 3, (x / 4) + hx, "%d", grid[1][1]);
	mvprintw(hy * 3, (x / 2) + hx, "%d", grid[1][2]);
	mvprintw(hy * 3, (x - hx), "%d", grid[1][3]);
	mvprintw((y / 2) + hy, hx, "%d", grid[2][0]);
	mvprintw((y / 2) + hy, (x / 4) + hx, "%d", grid[2][1]);
	mvprintw((y / 2) + hy, (x / 2) + hx, "%d", grid[2][2]);
	mvprintw((y / 2) + hy, (x - hx), "%d", grid[2][3]);
	mvprintw(y - hy, hx, "%d", grid[3][0]);
	mvprintw(y - hy, (x / 4) + hx, "%d", grid[3][1]);
	mvprintw(y - hy, (x / 2) + hx, "%d", grid[3][2]);
	mvprintw(y - hy, (x - hx), "%d", grid[3][3]);
	refresh();
}

void	ft_loop_it(int ***tab, int xmax, int ymax, int sig)
{
	char c;

	xmax = 0;
	ymax = 0;
	add_rand(tab, count_void_case(*tab));
	add_rand(tab, count_void_case(*tab));
	getmaxyx(stdsrc, ymax, xmax);
	if (ymax > 25 && xmax > 61)
	{
		ft_draw_grid(xmax -1, ymax -1);
		ft_print_grid(*tab, 0, 0);
		while ((c = getch()) != 27 && (ymax > 25 && xmax > 61) && sig == 0)
		{
			clear();
			ft_choice_direction(tab, c);
			ft_draw_grid(xmax -1, ymax - 1);
			ft_print_grid(*tab, 0, 0);
			if ((sig = ft_check(tab)) != 0)
				ft_end_game(sig);
			getmaxyx(stdscr, ymax, xmax);
			refresh();
		}
	}
	ft_size_error();
}
