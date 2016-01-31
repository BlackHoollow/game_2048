/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 18:50:56 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/31 21:46:15 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		choice_direction(int ***tab, int c)
{
	int		i;

	i = 0;
	if (c == 2)
		i = down(tab);
	else if (c == 3)
		i = up(tab);
	else if (c == 5)
		i = left(tab);
	else if (c == 4)
		i = right(tab);
	else
		return (0);
	if (i != 0)
		add_rand(tab, count_void_case(*tab));
	return (i);
}
