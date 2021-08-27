/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:45:47 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		size;
	char	*d;

	d = NULL;
	size = 0;
	while (src[size] != '\0')
		size++;
	d = malloc(sizeof(*d) * (size + 1));
	if (d == NULL)
		return (NULL);
	size = 0;
	while (src[size] != '\0')
	{
		d[size] = src[size];
		size++;
	}
	d[size] = '\0';
	return (d);
}
