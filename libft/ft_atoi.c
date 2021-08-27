/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:26:18 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	mk_num(const char *str)
{
	size_t	i;
	int		num;

	i = 0;
	num = 0;
	while (i < ft_strlen(str) && ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	char		ch;
	int			si;

	i = 0;
	si = 1;
	while (i < ft_strlen(str))
	{
		ch = str[i];
		if (ft_isdigit(ch))
			return (mk_num(&str[i]));
		else if (ch == '-' || ch == '+')
		{
			if (ch == '-')
				si = -1;
			if (ft_isdigit(str[i + 1]))
				return (si * mk_num(&str[i + 1]));
			return (0);
		}
		else if ((ch < 9 || ch > 13) && ch != 32)
			return (0);
		i++;
	}
	return (0);
}
