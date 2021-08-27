/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:35:39 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_get_lens(int len_s, unsigned int start, size_t len)
{
	len_s = len_s - start;
	if (len_s > (int) len)
		len_s = (int) len;
	if (len_s <= 0)
		len_s = 1;
	else
		len_s++;
	return (len_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*substr;

	if (!s)
		return (NULL);
	substr = malloc((ft_get_lens(ft_strlen(s), start, len)) * sizeof(char));
	if (substr)
	{
		i = 0;
		while (i < len && start < ft_strlen(s) && s[start + i] != '\0')
		{
			substr[i] = s[start + i];
			i++;
		}
		substr[i] = '\0';
		return (substr);
	}
	return (NULL);
}
