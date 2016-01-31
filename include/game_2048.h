/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 21:29:49 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/31 21:46:00 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <string.h>
# include <time.h>
# include <ncurses.h>

# define ENTER 10
# define ESCAPE 27
# define K_RIGHT 261
# define K_LEFT 260
# define K_UP 259
# define K_DOWN 258

enum	e_const
{
		WIN_VALUE = 2048
}		t_const;

/*
**		ft_choice.c
*/

int		choice_direction(int ***tab, int c);

/*
**		ft_initiate_tab.c
*/

int		**make_grid(void);
int		count_void_case(int **tab);
void	add_to_tab(int ***tab, int pos, int new);
void	add_rand(int ***tab, int n);

/*
**		ft_move_down.c
*/

int		move_down(int ***tab, int *check);
int		add_down(int ***tab, int *check);
int		down(int ***tab);

/*
**		ft_move_right.c
*/

int		move_right(int ***tab, int *check);
int		add_right(int ***tab, int *check);
int		right(int ***tab);

/*
**		ft_move_left.c
*/

int		move_left(int ***tab, int *check);
int		add_left(int ***tab, int *check);
int		left(int ***tab);

/*
**		ft_move_up.c
*/

int		move_up(int ***tab, int *check);
int		add_up(int ***tab, int *check);
int		up(int ***tab);

/*
**		ft_check.c
*/

int		check_if_win(int **tab);
int		is_winable(int checker);
int		check_if_loose(int **tab);

/*
**		ft_grid_maker.c
*/

int		ft_make_pat(int col, int row, int rpos);
int		ft_draw_grid(int col, int row);

/*
**		ft_loop.c
*/

int		ft_check(int ***grid);
void	ft_loop_it(int ***tab, int xmax, int ymax, int sig);

/*
**		ft_menu.c
*/

void	ft_menu(int col, int row);
void	ft_process_back(void);

/*
**		ft_core.c
*/

int		main(void);

#endif
