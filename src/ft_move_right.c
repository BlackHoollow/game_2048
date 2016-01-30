/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:37:35 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/30 21:28:36 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../libft/libft.h"

int		move_right(int ***tab, int *check)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 2;
		while (j >= 0)
		{
			if ((*tab)[i][j + 1] == 0 && (*tab)[i][j] != 0)
			{
				(*tab)[i][j + 1] = (*tab)[i][j];
				(*tab)[i][j] = 0;
				(*check)++;
				return (1);
			}
			j--;
		}
		i++;
	}
	return (0);
}

int		add_right(int ***tab)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 2;
		while (j >= 0)
		{
			if ((*tab)[i][j + 1] == (*tab)[i][j] && (*tab)[i][j] != 0)
			{
				(*tab)[i][j + 1] = (*tab)[i][j + 1] + (*tab)[i][j];
				(*tab)[i][j] = 0;
				return (1);
			}
			j--;
		}
		i++;
	}
	return (0);
}

int		**right(int **tab)
{
	int		i;

	i = 0;
	while (move_right(&tab, &i) == 1)
		;
	while (add_right(&tab) == 1)
		;
	while (move_right(&tab, &i) == 1)
		;
	return (tab);
}
