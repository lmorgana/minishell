/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:23:57 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
		if (str)
		{
			i = ft_strlcpy(str, s1, len_s1 + 1);
			i = ft_strlcpy(&str[i], s2, len_s2 + 1);
			return (str);
		}
	}
	return (NULL);
}
