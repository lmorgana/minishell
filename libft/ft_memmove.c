/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:28:56 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{	
	unsigned char	*u_dst;
	unsigned char	*u_src;

	if (len > 0)
	{
		if (dst - src <= 0)
			ft_memcpy(dst, src, len);
		else
		{
			u_dst = (unsigned char *) dst;
			u_src = (unsigned char *) src;
			len--;
			while (len > 0)
			{
				u_dst[len] = u_src[len];
				len--;
			}
			u_dst[0] = u_src[0];
		}
	}
	return (dst);
}
