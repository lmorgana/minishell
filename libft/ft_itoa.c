/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:14:49 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numb_r(int n)
{
	int	i;

	if (n == 0)
		return (1);
	if (n < 0)
		n = n * -1;
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static char	*ft_put_n(char *str, int n, int count)
{
	str[count] = '\0';
	if (n == 0)
		str[0] = '0';
	count--;
	while (n != 0)
	{
		str[count] = ft_abs(n % 10) + 48;
		n = n / 10;
		count--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*str;

	count = 0;
	if (n < 0)
		count++;
	count += ft_numb_r(n);
	str = malloc((count + 1) * sizeof(char));
	if (str)
	{
		if (n < 0)
		{
			n = n * -1;
			str[0] = '-';
		}
		str = ft_put_n(str, n, count);
		return (str);
	}
	return (NULL);
}
