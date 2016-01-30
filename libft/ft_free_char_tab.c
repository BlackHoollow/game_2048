/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 20:36:53 by mgras             #+#    #+#             */
/*   Updated: 2016/01/06 17:08:15 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_char_tab(char **tab)
{
	int		ss;

	ss = 0;
	if (!tab)
		return (NULL);
	while (tab[ss] != NULL)
	{
		free(tab[ss]);
		tab[ss] = NULL;
		ss++;
	}
	free(tab);
	tab = NULL;
	return (tab);
}
