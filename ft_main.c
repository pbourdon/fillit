/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishafie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:11:05 by ishafie           #+#    #+#             */
/*   Updated: 2015/12/20 23:20:27 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <string.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	t_tetri	*t_t;
	char	tminos[MAX + 1];
	char	*map;
	int		len;
	int		nb_t;
	t_tetri	*save;

	if (argc == 2 && (ft_strcpy(tminos, ft_get_tetriminos(argv[1], &len, &nb_t))) != NULL)
	{
		if (!(t_t = (t_tetri*)malloc(sizeof(t_tetri) * nb_t)))
			return (0);
		if (!(save = (t_tetri*)malloc(sizeof(t_tetri) * nb_t)))
			return (0);
		map = create_map(&len, &t_t[0]);
		map = modify_map(map, nb_t);
		t_t = ft_conversion_tetriminos(tminos, map, t_t);
		int i = 1;
		int id = 0;
		int l_jump = 0;
		char c = 'A';
		while (id < nb_t)
		{
			while (i < 4)
			{
				if (t_t[id].tc[i] == 3)
				{
					if (t_t[id].tc[i - 1] != t_t[id].tc[i] - 1)//ft adjust
						t_t[id].tc[i] = t_t[id].tc[i] + ((len / 16 * 4 + 4) - 4);
				}
				else if ((l_jump = t_t[id].tc[i] / 4) >= 1)
				{
					t_t[id].tc[i] = (t_t[id].tc[i] % 4) + (len / 16 * 4 + 4) * l_jump; // a revoir au cas ou

					if ((((t_t[id].tc[i] + 1) % 4) == 0))
						t_t[id].tc[i] = t_t[id].tc[i] + ((len / 16 * 4 + 4) - 4);
				}
				i++;
			}
			t_t[id].letter = c++;
			t_t[id].extend = 0;
			t_t[id].nb_un = 4;
			i = 1;
			id++;
		}
		t_t[0].nb_t = nb_t;
		t_t[0].l = len / 16 * 4 + 4;
		save = t_t;
		int nb_ext = ft_sqrt((t_t[0].nb_t * 4));
		i = 0;
		while (i++ < nb_ext)
			extend_map(map, t_t);
		save[0].extend = 0;
		if ((ft_add_to_map(map, t_t, 0, save)) == 0)
			ft_putstr("error");
		else
		{
/*			ft_putstr(map);
			ft_putstr("\n\n");
			ft_putnbr(t_t[0].nb_un);*/
			ft_display(map);
		}
	}
	else
		ft_putstr("error\n");
	return (0);
}
