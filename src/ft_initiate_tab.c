/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 21:47:55 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/31 19:27:13 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		**make_grid(void)
{
	int		**tab;
	int		i;
	int		j;

	i = 0;
	tab = (int **)malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		j = 0;
		tab[i] = (int *)malloc(sizeof(int) * 4);
		while (j < 4)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

int		count_void_case(int **tab)
{
	int		i;
	int		n;
	int		j;

	n = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == 0)
				n++;
			j++;
		}
		i++;
	}
	return (n);
}

void	add_to_tab(int ***tab, int pos, int new)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((*tab)[i][j] == 0)
			{
				if (pos == n)
				{
					(*tab)[i][j] = new;
					return ;
				}
				n++;
			}
			j++;
		}
		i++;
	}
}

void	add_rand(int ***tab, int n)
{
	int		which;
	int		pos;
	int		new;

	srand((unsigned int)time(NULL));
	which = rand() % 10;
	pos = rand() % n;
	if (which == 9)
		new = 4;
	else
		new = 2;
	ft_putnbr(pos);
	ft_putchar('\n');
	add_to_tab(tab, pos, new);
}
