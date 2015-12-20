/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishafie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:24:32 by ishafie           #+#    #+#             */
/*   Updated: 2015/12/18 19:09:07 by ishafie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <stdlib.h>

int		ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

static int	ft_signe(size_t *len, size_t *i, const char *s)
{
	int		signe;
	int		countplus;

	signe = 1;
	countplus = 0;
	while (s[*i] == '-' || s[*i] == '+' || s[*i] == ' ' || s[*i] == '\t' ||
		s[*i] == '\n' || s[*i] == '\v' || s[*i] == '\f' || s[*i] == '\r')
	{
		if (countplus == 1 && !ft_isalpha(s[*i]))
			return (0);
		if (s[*i] == '-')
		{
			countplus++;
			signe = -1;
		}
		if (s[*i] == '+')
			countplus++;
		if (countplus == 2 || s[*i] == '\200')
			return (0);
		*i = *i + 1;
		*len = *i;
	}
	return (signe);
}

int			ft_atoi(const char *str)
{
	size_t	len;
	size_t	i;
	int		result;
	size_t	multi;
	int		signe;

	len = 0;
	result = 0;
	multi = 1;
	i = 0;
	signe = ft_signe(&len, &i, str);
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	while (str[len] <= '9' && str[len++] >= '0')
		multi = multi * 10;
	while (multi >= 1 && str[i] <= '9' && str[i] >= '0')
	{
		multi /= 10;
		result = result + (str[i++] - '0') * multi;
	}
	return (result * signe);
}

static int	ft_nbrchar(int n, int *signe, int *multi, char **result)
{
	int		i;

	i = 0;
	*signe = 1;
	if (n == (-2147483648))
	{
		if (!(*result = (char*)malloc(sizeof(char) * 12)))
			return (-1);
		else
			ft_memcpy(*result, "-2147483648", 12);
	}
	if (n < 0)
	{
		n = -n;
		*signe = -1;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
		*multi *= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		len;
	int		multi;
	int		signe;
	char	*result;

	i = 0;
	multi = 1;
	if ((len = ft_nbrchar(n, &signe, &multi, &result) + 1) == -1)
		return (NULL);
	if (n == (-2147483648))
		return (result);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (signe == -1 && len++ > 0)
		result[i++] = '-';
	while (i < len)
	{
		result[i++] = ((n * signe) / multi) % 10 + '0';
		multi /= 10;
	}
	result[i] = '\0';
	return (result);
}
