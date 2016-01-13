/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishafie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 03:27:28 by ishafie           #+#    #+#             */
/*   Updated: 2016/01/09 06:09:45 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			ft_two_minimap(t_tetri *t_t)
{
	if (t_t[0].tc[1] == 1 && t_t[0].tc[2] == 8 && t_t[0].tc[3] == 9)
	{
		ft_putstr("AA\nAA\n");
		return (-1);
	}
	return (1);
}

void		ft_create_another_minimap(char *map)
{
	map[6] = '0';
	map[14] = '0';
	map[22] = '0';
	map[30] = '0';
	map[29] = '0';
	map[28] = '0';
	map[27] = '0';
}

void		ft_create_minimap(char *map)
{
	map[6] = '0';
	map[18] = '0';
	map[30] = '0';
	map[39] = '0';
	map[40] = '0';
	map[41] = '0';
	map[42] = '0';
}

int			ft_minimap(t_tetri *t_t, char *map, int nb_t)
{
	if (nb_t > 2)
		return (1);
	if (ft_two_minimap(t_t) == -1)
		return (0);
	if (nb_t == 2)
		ft_create_minimap(map);
	if (nb_t == 1)
		ft_create_another_minimap(map);
	return (1);
}
