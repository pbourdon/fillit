/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishafie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:19:00 by ishafie           #+#    #+#             */
/*   Updated: 2015/12/18 19:44:33 by ishafie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const	void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*strd;

	str = (unsigned char *)dst;
	strd = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		str[i] = strd[i];
		i++;
	}
	return (dst);
}
