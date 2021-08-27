/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:03:46 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		c;

	c = 0;
	i = 0;
	while (i < n && (unsigned char) s1[i] != '\0' && \
	 (unsigned char) s2[i] != '\0')
	{
		c = (unsigned char) s1[i] - (unsigned char) s2[i];
		if (c != 0)
			return (c);
		i++;
	}
	if (((unsigned char) s1[i] == '\0' || (unsigned char) \
	 s2[i] == '\0') && n - i > 0 )
		c = (unsigned char) s1[i] - (unsigned char) s2[i];
	return (c);
}
