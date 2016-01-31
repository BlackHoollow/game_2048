/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 18:37:01 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/31 21:12:41 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		main(void)
{
	initscr();
	keypad(stdscr, TRUE);
	raw();
	noecho();
	if (is_winable(WIN_VALUE))
		ft_menu(0, 0);
	else
	{
		mvprintw(5, 5, "This game is not winable");
		getch();
	}
	endwin();
	return (0);
}
