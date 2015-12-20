/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishafie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 21:23:06 by ishafie           #+#    #+#             */
/*   Updated: 2015/12/20 23:21:33 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <stdlib.h>

t_tetri			*ft_change_order(int *order, t_tetri *t_t)
{
	t_tetri		*new;
	int			i;
	int			nt;

	nt = 0;
	i = 0;
	if (!(new = (t_tetri*)malloc(sizeof(t_tetri) * (t_t[0]).nb_t + 1)))
		return (NULL);
	while (nt < (t_t[0]).nb_t)
	{
		while (i < 4)
		{
			new[nt].tc[i] = (t_t[order[nt]]).tc[i];
			new[nt].letter = t_t[order[nt]].letter;
			i++;
		}
		new[nt].available = 1;
		i = 0;
		nt ++;
	}
	new[0].nb_t = (t_t[0]).nb_t;
	new[0].l = (t_t[0]).l;
	return (new);
}

int				ft_max_combi(int n)
{
	if (n == 0 || n == 1)
		return (1);
	else
		return (n * ft_max_combi(n - 1));
}
void			ft_ok_to_add(char *map, t_tetri *t_t, int *index, int nt)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		map[*index + t_t[nt].tc[i]] = t_t[nt].letter;
		i++;
	}
	*index = 0;
	t_t[nt].available = 0;
}

int				ft_check_free(char *map, t_tetri *t_t, int *index, int nt)
{
	int		i;

	i = 0;
	t_t[nt].tc[i++] = 0;
	if ((nt) >= t_t[0].nb_t)
		return (nt);
	while (i < 4)
	{
		if (map[*index + t_t[nt].tc[i]] != '1' || t_t[nt].available == 0)
			return (nt);
		i++;
	}
	ft_ok_to_add(map, t_t, index, nt);
	if ((nt) >= t_t[0].nb_t)
		return (nt);
	return (nt + 1);
}

int		ft_check_take_best(char *ms, char *m)
{
	int		i;
	int		c_i;
	int		c_s;

	i = 0;
	c_i = 0;
	c_s = 0;
	while (m[i] != '\0')
	{
		if (m[i] == '1')
			c_i++;
		if (ms[i] == '1')
			c_s++;
		i++;
	}
	if (c_i == c_s)
		return (1);
	else if (c_i < c_s)
		return (0);
	else
		return (-1);
}

int		ft_take_best(char *ms, char *m)
{
	int		i;
	int		isave;
	char	c;
	int		instant;

	instant = ft_check_take_best(ms, m);
	c = 'A';
	i = 0;
	isave = -1;
	if (instant == 1)
	{
		while (m[i] != '\0')
		{

			if (m[i] <  ms[i] && m[i] != '1')
			{
			//	ft_putstr(ms);
				return (1);
			}
			else if (ms[i] < m[i] && ms[i] != '1')
				return (0);
			i++;
		}
		return (0);
	}
	else if (instant == 0)
		return (1);
	else
		return (0);
}

int		ft_add_to_map(char *map, t_tetri *t_t, int index, t_tetri *save)
{
	int		combi;
	int		max_combi;
	int		extend;
	int		order[t_t[0].nb_t + 1];
	int		nt;
	char	*mapsave;
	int		i;
	int		test;

	nt = 0;
	test = 0;
	save[0].extend = 0;
	max_combi = ft_max_combi(t_t[0].nb_t);
	combi = 0;
	extend = 0;
	t_t = save;
	i = 0;
	mapsave = ft_strdup(map);
	while (i++ < t_t[0].nb_t)
		order[i] = i;
	while (combi < max_combi)
	{
		 while (map[index++] != '\0') 
			if (map[index] == '1')
				if ((nt = ft_check_free(map, t_t, &index, nt)) == -1)
					index--;
		i = 0;
		while (i++ < t_t[0].nb_t)
			t_t[i].available = 1;
		if (nt >= t_t[0].nb_t)
		{
			if ((ft_take_best(mapsave, map)))
				ft_strcpy(mapsave, map);
			save[0].extend = nt;
		}
		index = 0;
		nt = 0;
		combi++;
		if (ft_change(order, t_t[0].nb_t) == 0)
			ft_strcpy(map, mapsave);
		map = ft_reset_map(map);
		t_t = ft_change_order(order, save);
	}
	i = 0;
	if (save[0].extend < t_t[0].nb_t)
		return (ft_add_to_map(extend_map(map, t_t), t_t, 0, save));
	ft_strcpy(map, mapsave);
	free(mapsave);
	return (1);
}
