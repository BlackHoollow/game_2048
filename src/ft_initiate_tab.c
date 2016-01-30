/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 21:47:55 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/30 22:35:47 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		**make_grid(void)
{
	int		**tab;
	int		i;

	i = 0;
	tab = (int **)malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		tab[i] = (int *)malloc(sizeof(int) * 4);
		ft_memset(tab[i], '0', 4);
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
			if (n == pos)
			{
				(*tab)[i][j] = new;
				return ;
			}
			if ((*tab)[i][j] == 0)
				n++;
			j++;
		}
		i++;
	}
}

int		**add_rand(int ***tab, int n)
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
	add_to_tab(tab, pos, new);
}
