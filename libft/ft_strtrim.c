/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 22:05:02 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_set_end(char const *s1, char const *set)
{
	int	i;
	int	len_s1;

	i = 0;
	len_s1 = ft_strlen(s1);
	while (len_s1 > 0)
	{
		if (ft_strchr(set, s1[len_s1]))
		{
			len_s1--;
			i++;
		}
		else
			break ;
	}
	return (i - 1);
}

static int	len_set_st(char const *s1, char const *set)
{
	int	i;
	int	len_s1;

	i = 0;
	len_s1 = ft_strlen(s1);
	while (i < len_s1)
	{
		if (ft_strchr(set, s1[i]))
			i++;
		else
			break ;
	}
	return (i);
}

static	char	*ft_str_db(const char *s1, char *s2, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		s2[i] = s1[start];
		start++;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len_s1;
	char	*ptr;
	int		sum;

	if (!s1 || !set)
		return (NULL);
	len_s1 = ft_strlen(s1);
	i = len_set_st(s1, set);
	sum = len_s1 - i - len_set_end(s1, set) + 1;
	if (sum < 0)
		sum = 1;
	ptr = malloc(sum);
	if (ptr)
	{
		return (ft_str_db(s1, ptr, i, len_s1 - len_set_end(s1, set)));
	}
	return (NULL);
}
