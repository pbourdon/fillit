/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishafie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:03:37 by ishafie           #+#    #+#             */
/*   Updated: 2015/12/20 00:56:08 by ishafie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char		*ft_conv_tetriminos(char *str)
{
	int		i;
	int		save;
	char	final[MAX + 1];

	i = 0;
	save = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			str[i] = '0';
		if (str[i] == '#')
			str[i] = '1';
		if (str[i] == '\n')
		{
			ft_strncat(final, &str[save], 4);
			if (str[i + 1] == '\n')
				i++;
			save = i + 1;
		}
		i++;
	}
	return (ft_atoa(final));
}

int			ft_check(char *s)
{
	int		i;
	int		nt;
	int		nl;

	i = 0;
	nt = 0;
	nl = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != '\n' && s[i] != '#' && s[i] != '.') || (i != 0 && ((i + 1)
				% 21) == 0 && (s[i] != '\n' || s[i + 1] == '\n')) || (i != 0 &&
				((i + 1 - nt) % 5) == 0 && s[i] != '\n') || nt == -1 || nt > 26)
			return (-1);
		if (s[i] == '\n')
		{
			nl++;
			if (nl != 0 && (((nl - (1 + nt)) % 4) == 0 && ((i - nt) % 5) == 0))
			{
				nt++;
				ft_check_tetri(s, i, &nt);
			}
		}
		i++;
	}
	ft_check_tetri(s, i, &nt);
	if (nt == 0)
		ft_check_tetri(s, i, &nt);
	if (nt == -1)
		return (-1);
	return (i);
}

char		*ft_get_tetriminos(char *av, int *len, int *nb_t)
{
	int		fd;
	char	tmp[MAX + 1];
	char	*final;

	fd = 0;
	*len = MAX;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL);
	if ((*len = read(fd, tmp, MAX)) == -1)
		return (NULL);
	tmp[*len + 1] = '\0';
	if (read(fd, tmp, 2) != 0 || *len < 20 || ft_check(tmp) != *len)
		return (NULL);
	final = ft_conv_tetriminos(tmp);
	*len = ft_strlen(final);
	*nb_t = *len / 16;
	if ((*len % 4) != 0)
		return (NULL);
	return (ft_atoa(final));
}
