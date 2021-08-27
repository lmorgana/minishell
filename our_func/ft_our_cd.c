/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_our_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:46:09 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 18:14:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static	int	ft_change_sis_env(char *name, char *buff_value, t_conf *conf)
{
	t_envs	*list;

	list = ft_get_by_name(name, conf->env);
	if (list)
	{
		free(list->value);
		list->value = ft_strdup(buff_value);
		if (list->value)
			return (1);
	}
	return (0);
}

static	int	ft_add_to_list_new_pwd(char *pwd_dir, t_conf *conf)
{
	char	new_pwd[256];
	char	old_pwd[256];
	char	*res;

	res = getcwd(old_pwd, 256);
	chdir(pwd_dir);
	if (getcwd(new_pwd, 256) != NULL && res)
	{
		if (ft_change_sis_env("PWD", new_pwd, conf) == 0)
			return (0);
		if (ft_change_sis_env("OLDPWD", old_pwd, conf) == 0)
			return (0);
		return (1);
	}
	return (0);
}

int	ft_set_new_pwd(char *pwd_dir, t_conf *conf)
{
	DIR		*dr;

	dr = opendir(pwd_dir);
	if (dr)
	{
		if (ft_add_to_list_new_pwd(pwd_dir, conf) == 0)
		{
			closedir(dr);
			return (0);
		}
		closedir(dr);
		return (1);
	}
	errno = ENOTDIR;
	g_exit_status.curr = 1;
	return (0);
}

static	int	ft_set_new_pwd_by_name(char	*name, t_exc *arg, t_conf *conf)
{
	t_envs	*list;

	list = ft_get_by_name(name, conf->env);
	if (list)
		ft_set_new_pwd(list->value, conf);
	else
	{
		if (name[0] == 'H')
			ft_print_error(arg->name, "HOME not set");
		else if (name[0] == 'O')
			ft_print_error(arg->name, "OLDPWD not set");
		g_exit_status.curr = 1;
	}
	return (1);
}

int	ft_our_cd(t_exc *arg, t_conf *conf)
{
	if (arg->flags[1])
	{
		if (ft_is_equal(arg->flags[1], "-"))
			ft_set_new_pwd_by_name("OLDPWD", arg, conf);
		else
			ft_set_new_pwd(arg->flags[1], conf);
	}
	else
	{
		ft_set_new_pwd_by_name("HOME", arg, conf);
	}
	if (errno)
		ft_print_error(arg->name, NULL);
	return (0);
}
