/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:47:17 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;

	if (dstsize > 0)
	{
		i = 0;
		n = 0;
		while (i < dstsize && dst[i])
			i++;
		while (i < dstsize - 1 && src[n] != '\0')
		{
			dst[i] = src[n];
			n++;
			i++;
		}
		if (i < dstsize)
			dst[i] = '\0';
		return (i + ft_strlen(src + n));
	}
	return (ft_strlen(src));
}
