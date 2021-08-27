/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:11:22 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*u_dst;
	unsigned char	*u_src;

	u_dst = (unsigned char *) dst;
	u_src = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		u_dst[i] = (unsigned char)u_src[i];
		if (u_src[i] == (unsigned char)c)
		{
			u_dst[i] = (unsigned char)c;
			return (&u_dst[i + 1]);
		}
		i++;
	}
	return (NULL);
}
