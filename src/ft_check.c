/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:22:39 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/31 20:29:29 by agomis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		check_if_win(int **tab)
{
	int		i;
	int		j;
	int		win;

	win = WIN_VALUE;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == win)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		is_winable(int checker)
{
	if (checker < 1)
		return (0);
	while (checker > 3)
		checker = checker / 2;
	if (checker == 2)
		return (1);
	else
		return (0);
}

int		check_if_loose(int **tab)
{
	int		**tmp;
	int		i;
	int		j;
	int		check;

	i = 0;
	tmp = (int **)malloc(sizeof (int *) * 4);
	while (i < 4)
	{
		j = 0;
		*tmp = (int *)malloc(sizeof (int) * 4);
		while (j < 4)
		{
			tmp[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
	check = (up(&tmp)) + (down(&tmp)) + (left(&tmp)) + (right(&tmp));
	if (check == 0)
		return (0);
	else
		return (1);
}
