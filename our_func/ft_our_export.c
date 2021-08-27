/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_our_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:46:18 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/21 10:19:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_print_export(char *buff_env)
{
	char	**name_value;

	name_value = ft_split(buff_env, '=');
	if (!name_value)
		return (0);
	if (name_value[1])
		printf("declare -x %s=\"%s\"\n", name_value[0], name_value[1]);
	else
	{
		if ((ft_strchr(buff_env, '=') != 0))
			printf("declare -x %s=\"\"\n", name_value[0]);
		else
			printf("declare -x %s\n", name_value[0]);
	}
	free(name_value[0]);
	free(name_value[1]);
	free(name_value);
	return (1);
}

int	ft_print_env(char *buff_env)
{
	char	**name_value;

	name_value = ft_split(buff_env, '=');
	if (!name_value)
		return (0);
	if (name_value[1])
		printf("%s=%s\n", name_value[0], name_value[1]);
	else
	{
		if ((ft_strchr(buff_env, '=') != 0))
			printf("%s=\n", name_value[0]);
	}
	free(name_value[0]);
	free(name_value[1]);
	free(name_value);
	return (1);
}

int	ft_show_all_vars(char **env)
{
	int		i;

	if (env == NULL)
		return (0);
	ft_sort_by_strncmp(env);
	i = 0;
	while (env[i])
	{
		ft_print_export(env[i]);
		i++;
	}
	ft_clear_arr(env);
	return (1);
}

int	ft_our_export(t_exc *arg, t_conf *conf)
{
	int	i;

	if (arg->flags[1] == 0)
		ft_show_all_vars(list_into_char(conf->env));
	else
	{
		i = 1;
		while (arg->flags[i])
		{
			if (ft_add_new_vars(arg->flags[i], conf->env) == 0)
				errno = EINVAL;
			i++;
		}
		if (errno)
		{
			ft_print_error(arg->name, NULL);
			return (0);
		}
	}
	return (1);
}
