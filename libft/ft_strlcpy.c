/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:29:09 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dst && src)
	{
		if (dstsize > 0)
		{
			i = 0;
			while (i < dstsize - 1 && src[i] != '\0')
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
		return (ft_strlen(src));
	}
	return (0);
}
