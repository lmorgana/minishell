/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:15:36 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (s && f)
	{
		i = 0;
		str = malloc((ft_strlen(s) + 1) * sizeof(char));
		if (str)
		{
			while (s[i] != '\0')
			{
				str[i] = f(i, (unsigned char) s[i]);
				i++;
			}
			str[i] = '\0';
			return (str);
		}
		return (NULL);
	}
	return (NULL);
}
