/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:59:33 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/21 10:19:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_clear_arr(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	return (1);
}

t_envs	*ft_get_by_name(char *name, t_envs *list)
{
	int		len;
	int		stat;
	t_envs	*ln;

	ln = NULL;
	while (list)
	{
		stat = 0;
		len = ft_strlen(list->name);
		if (list->name[len - 1] == '=')
		{
			list->name[len - 1] = '\0';
			stat = 1;
		}
		if (ft_is_equal(list->name, name))
			ln = list;
		if (stat == 1)
			list->name[len - 1] = '=';
		list = list->next;
	}
	return (ln);
}

int	ft_add_new_name(char **name_value, t_envs *list, char *var)
{
	char	*buff;

	if (ft_is_name_valid(name_value[0]) == 0)
	{
		errno = EINVAL;
		free(name_value[0]);
		free(name_value[1]);
	}
	else
	{
		if (name_value[1] || ft_strchr(var, '='))
		{
			buff = ft_strjoin(name_value[0], "=");
			free(name_value[0]);
			name_value[0] = buff;
		}
		if (ft_back_to_lst(name_value[0], name_value[1], &list))
			return (1);
	}
	return (0);
}

int	ft_change_var(char **name_value, t_envs *buff, char *var)
{
	if ((name_value[1] != 0 || ft_strchr(var, '=') != NULL) && \
	ft_strchr(buff->name, '=') == NULL)
	{
		free(buff->name);
		buff->name = ft_strjoin(name_value[0], "=");
	}
	if (name_value[1])
	{
		free(buff->value);
		buff->value = name_value[1];
	}
	free(name_value[0]);
	free(name_value);
	if (!buff->name)
		return (0);
	return (1);
}

int	ft_add_new_vars(char *var, t_envs *list)
{
	char	**name_value;
	t_envs	*buff;

	if (var[0] == '\0')
		return (0);
	name_value = ft_split(var, '=');
	if (name_value == NULL)
		return (0);
	buff = ft_get_by_name(name_value[0], list);
	if (buff)
	{
		if (ft_change_var(name_value, buff, var) == 0)
			return (0);
	}
	else
	{
		ft_add_new_name(name_value, list, var);
		free(name_value);
	}
	return (1);
}
