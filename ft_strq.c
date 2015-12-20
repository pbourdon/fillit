#include "ft_fillit.h"

int		ft_sqrt(int nb)
{
	int		i;

	i = 0;
	while ((i * i) <= nb)
		i++;
	if ((i - 1) * (i - 1) == nb)
		return (i - 5);
	return (i - 4);
}

void	ft_display(char *map)
{
	int		i;
	int		compteur;
	int		number_of_lines;

	i = 0;
	number_of_lines = 0;
	compteur = ft_compt(map);
	while (number_of_lines * number_of_lines != compteur)
		number_of_lines++;
	compteur = 0;
	while (compteur != number_of_lines)
	{
		if (ft_isalpha(map[i]))
			ft_putchar(map[i]);
		else if (map[i] == '1')
			ft_putchar('.');
		if (map[i] == '\n')
		{
			ft_putchar('\n');
			compteur++;
		}
		i++;
	}
}

int		ft_compt(char *map)
{
	int		i;
	int		compteur;

	compteur = 0;
	i = 0;
	while (map[i++] != '\0')
	{
		if (ft_isalpha(map[i]) || map[i] == '1')
			compteur++;
	}
	return (compteur);
}
