/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_our_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:05:55 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/21 10:19:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static	int	ft_is_valid(char *str)
{
	int	i;
	int	stat;

	i = 0;
	stat = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] == '-')
			stat = 1;
		if (i > 0 && str[i] != 'n')
			return (0);
		i++;
	}
	return (stat);
}

static	int	ft_print_echo(t_exc *arg)
{
	int	i;
	int	stat;

	stat = 0;
	i = 1;
	while (ft_is_valid(arg->flags[i]))
	{
		stat = 1;
		i++;
	}
	while (arg->flags[i])
	{
		write(1, arg->flags[i], ft_strlen(arg->flags[i]));
		if (arg->flags[i + 1] && arg->flags[i][0] != '\0')
			write(1, " ", 1);
		i++;
	}
	if (stat == 0)
		write(1, "\n", 1);
	return (1);
}

static	int	ft_for_home(t_exc *arg, t_conf *conf)
{
	char	*value;

	value = ft_my_getenv("HOME", conf->env);
	if (value)
		printf("%s\n", ft_my_getenv("HOME", conf->env));
	else
	{
		ft_print_error(arg->name, "HOME not set");
		g_exit_status.curr = 1;
	}
	return (1);
}

int	ft_our_echo(t_exc *arg, t_conf *conf)
{
	if (arg->flags[0])
	{
		if (arg->flags[1])
		{
			if (ft_is_equal(arg->flags[1], "~"))
			{
				ft_for_home(arg, conf);
			}
			else
			{
				ft_print_echo(arg);
				return (1);
			}
		}
		else if (arg->inFd == 0 && arg->outFd == 0)
		{
			write(1, "\n", 1);
		}
	}
	return (0);
}
