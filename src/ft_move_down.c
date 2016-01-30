/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:37:35 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/30 21:30:01 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft/libft.h"

int		move_down(int ***tab, int *check)
{
	int		i;
	int		j;

	j = 0;
	while (j < 4)
	{
		i = 2;
		while (i >= 0)
		{
			if ((*tab)[i + 1][j] == 0 && (*tab)[i][j] != 0)
			{
				(*tab)[i + 1][j] = (*tab)[i][j];
				(*tab)[i][j] = 0;
				(*check)++;
				return (1);
			}
			i--;
		}
		j++;
	}
	return (0);
}

int		add_down(int ***tab)
{
	int		i;
	int		j;

	j = 0;
	while (j < 4)
	{
		i = 2;
		while (i >= 0)
		{
			if ((*tab)[i + 1][j] == (*tab)[i][j] && (*tab)[i][j] != 0)
			{
				(*tab)[i + 1][j] = (*tab)[i + 1][j] + (*tab)[i][j];
				(*tab)[i][j] = 0;
				return (1);
			}
			i--;
		}
		j++;
	}
	return (0);
}

int		**down(int **tab)
{
	int		i;

	i = 0;
	while (move_down(&tab, &i) == 1)
		;
	while (add_down(&tab) == 1)
		;
	while (move_down(&tab, &i) == 1)
		;
	return (tab);
}
