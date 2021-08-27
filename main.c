/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 00:19:30 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/21 00:19:32 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_exc_path(t_exc *arg, t_conf *conf)
{
	char	*path_bin;

	path_bin = ft_check_for_bin(arg->name, conf);
	if (path_bin)
	{
		arg->path_bin = path_bin;
		return (1);
	}
	free(path_bin);
	return (0);
}

int	ft_process(t_conf *conf)
{
	if (ft_get_pids(conf) == 0)
		return (0);
	if (ft_start_all_exc(conf->args, conf))
	{
		if (ft_wait_for_all_pids(conf->args) == 0)
			return (0);
		return (1);
	}
	ft_print_error("", "error malloc\n");
	if (g_exit_status.curr == 0)
		g_exit_status.curr = 42;
	return (0);
}

int	ft_init_ms(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	g_exit_status.prev = 0;
	g_exit_status.curr = 0;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &ctrl_c_hook);
	return (1);
}

static	int	ft_update(void)
{
	signal(SIGINT, &ctrl_c_hook);
	signal(SIGQUIT, SIG_IGN);
	g_exit_status.prev = g_exit_status.curr;
	g_exit_status.curr = 0;
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	t_conf	conf;
	char	*line;
	t_token	*token;

	ft_init_ms(argc, argv);
	conf.env = ft_create_lists_from_env(env);
	while (1)
	{
		conf.args = NULL;
		line = readline("\033[0;31m\033[1mms : \033[0m");
		if (!line)
			ctrl_D_hook(12);
		add_history(line);
		token = parser(line, conf.env);
		if (token)
		{
			conf.args = convertTokenInExc(token);
			if (conf.args)
				ft_process(&conf);
			ft_clear_exc(conf.args);
		}
		ft_update();
		clear_memory(&token, conf.args);
	}
	return (0);
}
