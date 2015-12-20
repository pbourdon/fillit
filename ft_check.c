/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishafie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:05:49 by ishafie           #+#    #+#             */
/*   Updated: 2015/12/20 03:30:07 by ishafie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		ft_check_tetriduo(char *s, int i)
{
	if (s[i + 1] == '#')
	{
		if (s[i + 10] == '#' && s[i + 11] == '#')
			return (-1);
	}
	else if (s[i - 1] == '#')
	{
		if (s[i + 10] == '#' && s[i + 9] == '#')
			return (-1);
	}
	else if (s[i + 5] == '#')
	{
		if (s[i + 2] == '#' && s[i + 7] == '#')
			return (-1);
	}
	else if (s[i - 5] == '#')
	{
		if (s[i + 2] == '#' && s[i - 7] == '#')
			return (-1);
	}
	return (0);
}

int		ft_check_tetriduo_bis(char *s, int i, int *adj)
{
	if (s[i + 1] == '#')
	{
		if (s[i + 5] == '#' || s[i - 5] == '#' || s[i - 1] == '#')
			*adj = 1;
	}
	else if (s[i - 1] == '#')
	{
		if (s[i + 5] == '#' || s[i - 5] == '#' || s[i + 1] == '#')
			*adj = 1;
	}
	else if (s[i + 5] == '#')
	{
		if (s[i - 1] == '#' || s[i - 5] == '#' || s[i + 1] == '#')
			*adj = 1;
	}
	else if (s[i - 5] == '#')
	{
		if (s[i - 1] == '#' || s[i + 5] == '#' || s[i + 1] == '#')
			*adj = 1;
	}
	return (1);
}

int		ft_check_tetri(char *s, int index, int *nt)
{
	int		i;
	int		c_d;
	int		adj;

	c_d = 0;
	adj = 0;
	i = (index - 20);
	while (i <= index)
	{
		if (s[i] == '#')
		{
			if (s[i + 1] != '#' && s[i - 1] != '#' && s[i + 5] != '#'
				&& s[i - 5] != '#')
				*nt = -1;
			else if (ft_check_tetriduo_bis(s, i, &adj) == -1)
				*nt = -1;
			c_d++;
		}
		i++;
	}
	if (adj == 0)
		*nt = -1;
	if (c_d != 4)
		*nt = -1;
	return (0);
}
