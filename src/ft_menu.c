/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 21:13:13 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/31 21:44:07 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	ft_process_back(void)
{
	int		**tab;

	tab = make_grid();
	clear();
	ft_loop_it(&tab, 4, 4, 0);
}

void	ft_menu(int col, int row)
{
	ft_process_back();
	return ;
}
