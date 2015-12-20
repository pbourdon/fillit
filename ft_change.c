/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 15:26:03 by pbourdon          #+#    #+#             */
/*   Updated: 2015/12/19 21:42:42 by ishafie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <stdlib.h>

int		*ft_plus_one(int *tab, int nb_t)
{
	int		index;

	index = nb_t - 1;
	tab[index]++;
	while (index > 0)
	{
		if (tab[index] > 9)
		{
			tab[index] = 0;
			tab[index - 1]++;
		}
		index--;
	}
	return (tab);
}

int		ft_check_nb_t(int *tab, int nb_t)
{
	int		index;

	index = nb_t - 1;
	while (index >= 0)
	{
		if (tab[index] > nb_t - 1)
			return (1);
		index--;
	}
	return (0);
}

int		ft_check_double(int *tab, int nb_t)
{
	int		index;
	int		c;
	int		index2;

	index = 0;
	index2 = 0;
	while (index < nb_t)
	{
		c = tab[index];
		index2 = 0;
		while (index2 < nb_t)
		{
			if (tab[index2] == c && index2 != index)
				return (1);
			index2++;
		}
		index++;
	}
	return (0);
}

int		ft_change(int *tab, int nb_t)
{
	tab = ft_plus_one(tab, nb_t);
	while (ft_check_nb_t(tab, nb_t) == 1 || ft_check_double(tab, nb_t) == 1)
	{
		tab = ft_plus_one(tab, nb_t);
		if(tab[0] > nb_t)
		{
			tab[0] = 111;
			return (0);
		}
	}
	return (1);
}
/*
int		main(void)
{
	int		tab[4];
	int		index;
	int		index2 = 0;

	index = 0;
	// tab = malloc(sizeof(int) * 9 + 1);
	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 2;
	tab[3] = 3;

	tab[3] = 8;
	tab[4] = 3;
	tab[5] = 2;
	tab[6] = 9;

	index = 0;
	while (index2 < 999)
	{
		index = 0;
		ft_change2(tab, 4);
		while (index < 4)
		{
			printf("%d", tab[index]);
			index++;
		}
		printf("\n");
		index2++;
		if (tab[0] == 111)
			return (0);
	}
	return (0);
}
*/
