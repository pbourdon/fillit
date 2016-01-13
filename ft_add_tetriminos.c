/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishafie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 21:38:00 by ishafie           #+#    #+#             */
/*   Updated: 2016/01/07 19:59:38 by ishafie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

t_tetri		ft_decode_tetriminos(char *s, int save, int i)
{
	t_tetri	tetri;
	int		nc;

	nc = 0;
	tetri.tc[0] = 0;
	while (save < i)
	{
		if (s[save] == '1')
		{
			tetri.tc[nc] = save - tetri.tc[0];
			tetri.available = 1;
			nc++;
		}
		save++;
	}
	return (tetri);
}

t_tetri		*ft_conversion_tetriminos(char *s, const char *map, t_tetri *t_t)
{
	int		i;
	int		save;
	int		nt;

	nt = 0;
	i = 0;
	save = 0;
	while (s[i] != '\0' && map)
	{
		if (((i + 1) % 16) == 0 && i != 0)
		{
			t_t[nt] = ft_decode_tetriminos(s, save, i + 1);
			nt++;
			save = i + 1;
		}
		i++;
	}
	return (t_t);
}
