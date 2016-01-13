/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishafie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:11:05 by ishafie           #+#    #+#             */
/*   Updated: 2016/01/12 21:21:58 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <string.h>
#include <stdlib.h>

void		ft_help_renew_bis(t_tetri *t_t, int id, int len, int l_jump)
{
	int		i;

	i = 1;
	while (i < 4)
	{
		if ((t_t[id].tc[i] == 3 && t_t[id].tc[i + 1] == 4) ||
			(i == 1 && t_t[id].tc[i] == 2))
		{
			t_t[id].tc[0] = 0;
			t_t[id].tc[i] = t_t[id].tc[i] + ((len / 16 * 4 + 4) - 4);
		}
		else if ((l_jump = t_t[id].tc[i] / 4) >= 1)
		{
			t_t[id].tc[i] = (t_t[id].tc[i] % 4) + (len / 16 * 4 + 4) * l_jump;
			if ((((t_t[id].tc[i] + 1) % 4) == 0))
				t_t[id].tc[i] = t_t[id].tc[i] + ((len / 16 * 4 + 4) - 4);
		}
		i++;
	}
}

int			ft_renew_topcase(t_tetri *t_t, int nb_t, int len)
{
	int		id;
	int		l_jump;
	char	c;

	id = 0;
	l_jump = 0;
	c = 'A';
	while (id < nb_t)
	{
		ft_help_renew_bis(t_t, id, len, l_jump);
		t_t[id].letter = c++;
		t_t[id].extend = 0;
		t_t[id].nb_un = 4;
		id++;
	}
	t_t[0].nb_t = nb_t;
	t_t[0].l = len / 16 * 4 + 4;
	return (1);
}

int			main(int argc, char **argv)
{
	t_tetri	*t_t;
	char	tminos[MAX + 1];
	char	*map;
	int		len;
	int		nb_t;

	if (argc == 2 && (ft_strcpy(tminos, ft_gt(argv[1], &len, &nb_t))) != NULL)
	{
		if (!(t_t = (t_tetri*)malloc(sizeof(t_tetri) * nb_t)))
			return (0);
		map = create_map(&len, &t_t[0]);
		map = modify_map(map);
		t_t = ft_conversion_tetriminos(tminos, map, t_t);
		ft_renew_topcase(t_t, nb_t, len);
		if (ft_minimap(t_t, map, nb_t) == 0)
			return (0);
		nb_t = ft_sqrt(t_t[0].nb_t * 4);
		while (nb_t > 0 && nb_t--)
			extend_map(map, t_t);
		if ((ft_backtracking(map, t_t, 0, 0)))
			ft_display(map);
	}
	else
		ft_putstr("error\n");
	return (0);
}
