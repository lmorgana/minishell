/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:55:32 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_num_c(char const *s, char c)
{
	int	i;
	int	count;
	int	stat;

	stat = 0;
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && stat)
		{
			count++;
			stat = 0;
		}
		if (s[i] != c)
			stat = 1;
		i++;
	}
	if (s[i] == '\0' && i > 0 && s[i - 1] != c)
		count++;
	return (count);
}

static	char	**ft_mall_err(char **tb, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(tb[i]);
		i++;
	}
	free(tb);
	return (NULL);
}

static	char	**ft_fill_tb(char **tb, char const *s, char c)
{
	size_t	i;
	int		last_i;
	int		j;

	i = 0;
	j = 0;
	last_i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == c || s[i] == '\0')
		{
			if (i - last_i > 0)
			{
				tb[j] = ft_substr(s, last_i, i - last_i);
				if (!tb[j])
					return (ft_mall_err(tb, j));
				j++;
			}
			last_i = i + 1;
		}
		i++;
	}
	tb[j] = 0;
	return (tb);
}

char	**ft_split(char const *s, char c)
{
	int		len_tb;
	char	**tb;

	if (s)
	{
		len_tb = ft_num_c(s, c) + 1;
		tb = malloc(len_tb * sizeof(char *));
		if (!tb)
			return (NULL);
		tb = ft_fill_tb(tb, s, c);
		return (tb);
	}
	return (NULL);
}
