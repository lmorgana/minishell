/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mk_our_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:46:01 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_our_pwd(t_exc *arg)
{
	char	buff[256];

	(void) arg;
	if ((getcwd(buff, 256)))
	{
		printf("%s\n", buff);
		return (1);
	}
	return (0);
}

static	int	ft_our_env(t_exc *arg, t_conf *conf)
{
	char	**env;
	int		i;

	(void) arg;
	env = list_into_char(conf->env);
	if (env)
	{
		i = 0;
		while (env[i])
		{
			ft_print_env(env[i]);
			i++;
		}
		ft_clear_arr(env);
		return (1);
	}
	return (0);
}

int	ft_mk_our_func(t_exc *arg, t_conf *conf)
{
	if (ft_is_equal(arg->name, "echo"))
		ft_our_echo(arg, conf);
	if (ft_is_equal(arg->name, "pwd"))
		ft_our_pwd(arg);
	if (ft_is_equal(arg->name, "export"))
		ft_our_export(arg, conf);
	if (ft_is_equal(arg->name, "env"))
		ft_our_env(arg, conf);
	return (1);
}
