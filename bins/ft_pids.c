/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:43:27 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static	int	ft_take_redirects(t_conf *conf, int i)
{
	if (conf->args[i].inFd == -1 || conf->args[i].outFd == -1)
		return (0);
	if (conf->args[i].inFd > 0)
		conf->args[i].pipe[0] = conf->args[i].inFd;
	if (conf->args[i].outFd > 1)
		conf->args[i].pipe[1] = conf->args[i].outFd;
	return (1);
}

static	int	ft_take_pipe_stat(t_conf *conf, int i, int *arr_pipe)
{
	if (conf->args[i].pipe_stat[0] == 1)
	{
		conf->args[i].pipe[0] = arr_pipe[0];
		arr_pipe[0] = 0;
	}
	if (conf->args[i].pipe_stat[1] == 1)
	{
		if (pipe(arr_pipe) < 0)
			return (0);
		conf->args[i].pipe[1] = arr_pipe[1];
	}
	return (1);
}

int	ft_get_pids(t_conf *conf)
{
	int	i;
	int	arr_pipe[2];

	i = 0;
	while (conf->args[i].name)
	{
		if (ft_take_pipe_stat(conf, i, arr_pipe) == 0)
			return (0);
		if (ft_take_redirects(conf, i) == 0)
			return (0);
		i++;
	}
	return (1);
}
