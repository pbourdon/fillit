/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishafie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:50:21 by ishafie           #+#    #+#             */
/*   Updated: 2015/12/18 17:54:11 by ishafie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <string.h>
#include <stdlib.h>

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncat(char *s1, const char *s2, int n)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	while ((s1[len + i] = s2[i]) != '\0' && i < n)
		i++;
	s1[len + i] = '\0';
	return (s1);
}

char	*ft_strcpy(char *dst, const char *src)
{
	char	*str;

	if (!src)
		return (NULL);
	str = dst;
	while ((*str++ = *src++) != '\0')
		;
	return (dst);
}

char	*ft_atoa(char *str)
{
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(s1);
	if (!(str = (char *)malloc(sizeof(*str) * len)))
		return (NULL);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
