/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:29:47 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last_c;

	i = 0;
	last_c = -1;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			last_c = i;
		i++;
	}
	if (last_c >= 0)
		return ((char *) &s[last_c]);
	if (c == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
