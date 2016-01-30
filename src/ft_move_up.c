/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:37:35 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/30 21:29:11 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../libft/libft.h"

int		move_up(int ***tab, int *check)
{
	int		i;
	int		j;

	j = 0;
	while (j < 4)
	{
		i = 1;
		while (i <= 3)
		{
			if ((*tab)[i - 1][j] == 0 && (*tab)[i][j] != 0)
			{
				(*tab)[i - 1][j] = (*tab)[i][j];
				(*tab)[i][j] = 0;
				(*check)++;
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int		add_up(int ***tab)
{
	int		i;
	int		j;

	j = 0;
	while (j < 4)
	{
		i = 1;
		while (i <= 3)
		{
			if ((*tab)[i - 1][j] == (*tab)[i][j] && (*tab)[i][j] != 0)
			{
				(*tab)[i - 1][j] = (*tab)[i - 1][j] + (*tab)[i][j];
				(*tab)[i][j] = 0;
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int		**up(int **tab)
{
	int		i;

	i = 0;
	while (move_up(&tab, &i) == 1)
		;
	while (add_up(&tab) == 1)
		;
	while (move_up(&tab, &i) == 1)
		;
	return (tab);
}
