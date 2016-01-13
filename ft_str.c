/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishafie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 12:56:49 by ishafie           #+#    #+#             */
/*   Updated: 2016/01/07 20:00:21 by ishafie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		ft_putchar(s[i++]);
}

char		*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	while ((s1[len + i] = s2[i]) != '\0')
		i++;
	s1[len + i] = '\0';
	return (s1);
}

static int	ft_max(int n)
{
	if (n == (-2147483648))
	{
		ft_putstr("-2147483648");
		return (1);
	}
	else if (n == 0)
	{
		ft_putchar('0');
		ft_putchar('\n');
		return (1);
	}
	else
		return (0);
}

void		ft_putnbr(int n)
{
	int	i;
	int	save;

	save = 0;
	i = 1;
	if (ft_max(n))
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	save = n;
	while (n >= 10)
	{
		i *= 10;
		n /= 10;
	}
	n = save;
	while (n >= 1)
	{
		ft_putchar((save / i) % 10 + '0');
		i /= 10;
		n /= 10;
	}
}
