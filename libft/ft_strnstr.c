/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:36:49 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_ch_hn(const char *haystack, \
	const char *needle, size_t len, size_t n)
{
	size_t	i;

	if (n > len)
		return (0);
	if (len - n < ft_strlen(needle))
		return (0);
	i = 0;
	while (n < len && haystack[i] != '\0' && needle[i] != '\0')
	{
		if (haystack[i] != needle[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*s;
	int		len_h;
	int		len_n;

	len_h = ft_strlen(haystack);
	len_n = ft_strlen(needle);
	if (len_n == 1)
		return (ft_memchr(haystack, needle[0], len));
	if (len_n == 0)
		return ((char *) haystack);
	if (haystack[0] == '\0')
		return (NULL);
	s = ft_memchr(haystack, needle[0], len_h);
	while (s)
	{
		if (ft_ch_hn(s, needle, len, s - haystack))
			return (s);
		s = ft_memchr(s + 1, needle[0], len_h);
	}
	return (NULL);
}
