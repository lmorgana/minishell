/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:10:52 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	u_w;
	unsigned char	*u_s;
	size_t			i;

	u_w = (unsigned char) c;
	u_s = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (u_s[i] == u_w)
			return (&u_s[i]);
		i++;
	}
	return (NULL);
}
