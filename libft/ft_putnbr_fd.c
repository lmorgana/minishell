/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:53:52 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_putnb_fd(int n, int fd)
{
	if (n != 0)
	{
		ft_putnb_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		else
		{
			write(fd, "-", 1);
			ft_putnb_fd(n * -1, fd);
		}
	}
	else if (n == 0)
		write(fd, "0", 1);
	else
		ft_putnb_fd(n, fd);
}
