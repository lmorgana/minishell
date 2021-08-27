/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mk_execve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:58:23 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 17:40:45 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static	int	ft_dup_in_out(int fd_in, int fd_out)
{
	if (fd_in >= 0 && fd_out >= 1)
	{
		if (fd_in != 0)
		{
			if (dup2(fd_in, 0) < 0)
				return (0);
			close(fd_in);
		}
		if (fd_out != 1)
		{
			if (dup2(fd_out, 1) < 0)
				return (0);
			close(fd_out);
		}
		return (1);
	}
	return (0);
}

int	ft_mk_cmd(t_exc *arg, t_conf *conf)
{
	if (arg->type == 1)
	{
		if (ft_strchr(arg->name, '/') != NULL)
			arg->path_bin = ft_is_path_exist(arg->name);
		else
			ft_exc_path(arg, conf);
		if (arg->path_bin)
			execve(arg->path_bin, arg->flags, list_into_char(conf->env));
		ft_print_error(arg->name, "command not found");
		exit(1);
	}
	if (arg->type == 2)
		ft_mk_our_func(arg, conf);
	return (1);
}

static	int	ft_mk_execve_bins(t_exc *arg, t_conf *conf)
{
	int		pid;

	pid = fork();
	if (pid < 0)
		return (printf("Error with fork()\n") * 0);
	else if (pid == 0)
	{
		errno = 0;
		if (ft_dup_in_out(arg->pipe[0], arg->pipe[1]) == 1)
		{
			ft_mk_cmd(arg, conf);
		}
		exit(0);
	}
	else
	{
		signal(SIGINT, &ctrl_c_hook_for_ch);
		signal(SIGQUIT, &ctrl_sh);
		arg->ch_pid = pid;
		if (arg->pipe[0] > 0)
			close(arg->pipe[0]);
		if (arg->pipe[1] > 1)
			close(arg->pipe[1]);
		return (pid);
	}
}

int	ft_start_all_exc(t_exc *args, t_conf *conf)
{
	int	i;

	i = 0;
	while (args[i].name != 0)
	{
		if (ft_is_equal(args[i].name, "cd"))
			ft_our_cd(&args[i], conf);
		else if (ft_is_equal(args[i].name, "export"))
		{
			if (args[i].flags[1] != 0)
				ft_our_export(&args[i], conf);
			else if (ft_mk_execve_bins(&args[i], conf) == 1)
				return (0);
		}
		else if (ft_is_equal(args[i].name, "exit"))
			ft_our_exit(&args[i]);
		else if (ft_is_equal(args[i].name, "unset"))
			ft_our_unset(&args[i], conf);
		else if (ft_mk_execve_bins(&args[i], conf) == 1)
			return (0);
		i++;
	}
	return (1);
}
