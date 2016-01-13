/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishafie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 20:07:19 by ishafie           #+#    #+#             */
/*   Updated: 2016/01/09 02:11:52 by ishafie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_ok_to_add(char *map, t_tetri *t_t, int index, int nt)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		map[index + t_t[nt].tc[i]] = t_t[nt].letter;
		i++;
	}
	t_t[nt].available = 0;
}

int		ft_check_free(char *map, t_tetri *t_t, int index, int nt)
{
	int		i;

	i = 0;
	t_t[nt].tc[i++] = 0;
	while (i < 4)
	{
		if (map[index + t_t[nt].tc[i]] != '1' || t_t[nt].available == 0)
			return (-1);
		i++;
	}
	return (1);
}

int		ft_restart_tetri(t_tetri *t_t)
{
	int		i;

	i = 0;
	while (i < t_t[0].nb_t)
	{
		t_t[i].available = 1;
		i++;
	}
	return (1);
}

int		ft_delete_tetri(char *map, t_tetri *t_t, int index, int nt)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (map[index + t_t[nt].tc[i]] == '1')
			return (0);
		map[index + t_t[nt].tc[i]] = '1';
		i++;
	}
	return (1);
}

int		ft_backtracking(char *map, t_tetri *t_t, int index, int nt)
{
	if (nt >= t_t[0].nb_t)
		return (1);
	while (map[index] != '\0')
	{
		if (map[index] == '1')
		{
			if (ft_check_free(map, t_t, index, nt) == 1)
			{
				t_t[nt].index = index;
				ft_ok_to_add(map, t_t, index, nt);
				if ((ft_backtracking(map, t_t, 0, nt + 1)) == 1)
					return (1);
			}
		}
		index++;
	}
	t_t[nt - 1].available = 1;
	if (nt != 0)
		ft_delete_tetri(map, t_t, t_t[nt - 1].index, nt - 1);
	if (nt == 0)
	{
		map = extend_map(map, t_t);
		ft_backtracking(map, t_t, 0, 0);
	}
	return (-1);
}
