/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:01:19 by pbourdon          #+#    #+#             */
/*   Updated: 2015/12/20 04:51:58 by ishafie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

char	*ft_reset_map(char *map)
{
	int		i;

	i = 0;
	while (map[i] != '\0')
	{
		if (ft_isalpha(map[i]))
			map[i] = '1';
		i++;
	}
	return (map);
}

char	*modify_map(char *map, int nt)
{
	int		index;
	int		index2;
	int		index3;
	int		index4;

	index = -1;
	index2 = -1;
	index3 = 0;
	index4 = 0;
	while (map[++index] != '\0')
	{
		if (map[index - 1] == '\n' || index == 0)
		{
			index2 = -1;
			while (index2++ < 2)
				map[index++] = '3';
			while (index2++ < 7)
				if (index4 < 4)
					map[index++] = '1';
			index3++;
			index4++;
		}
	}
	return (map);
}

char	*create_map(int *len, t_tetri *t_t)
{
	int index;
	int index2;
	int limit;
	char map[15187];

//	t_t[0].nb_un = t_t[0].nb_un + 1;
	(*t_t).l = *len / 16 * 4 + 4;
	limit = ((*t_t).l - 1) * ((*t_t).l - 1);
	index2 = 1;
	index = 0;
	while (index < limit)
	{
		if (index2 == (*t_t).l)
		{
			map[index] = '\n';
			index2 = 0;
			limit++;
		}
		else
			map[index] = '0';
		index2++;
		index++;
	}
	map[index] = '\0';
	return (ft_atoa(map));
}

char	*extend_map(char *map, t_tetri *t_t)
{
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	t_t[0].nb_un = t_t[0].nb_un + 1;
	while (map[index++] != '\0')
		if ((map[index - 1] == '1' || (map[index - 1] < 91 && map[index - 1] >
						64)) && (map[index] == 48))
			map[index++] = '1';
	index = 0;
	while (map[index++] != '\0')
	{
		if (index2 == 0)
			while (map[index++] > 48 && map[index] != '3')
				index2++;
		if (map[index] == '\n')
			if (map[index + 4] == '0')
			{
				index = index + 4;
				while (index2-- > 0)
					map[index++] = '1';
			}
	}
	return (map);
}
