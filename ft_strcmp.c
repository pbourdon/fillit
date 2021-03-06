/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishafie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:24:52 by ishafie           #+#    #+#             */
/*   Updated: 2015/12/18 19:44:52 by ishafie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s;
	unsigned char	*sd;
	size_t			i;

	s = (unsigned char*)s1;
	sd = (unsigned char*)s2;
	i = 0;
	while (s[i] == sd[i])
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	if (s[i] > sd[i])
		return (sd[i] + s[i]);
	else
		return (s[i] - sd[i]);
}
