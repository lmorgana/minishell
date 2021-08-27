/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:44:57 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 10:44:59 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_clear_env(t_envs *list)
{
	t_envs	*buff;

	while (list)
	{
		if (list->name)
			free(list->name);
		if (list->value)
			free(list->value);
		buff = list;
		list = list->next;
		free(buff);
	}
	return (1);
}

int	ft_is_name_valid(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (i == 0 && !ft_isalpha(name[i]))
			return (0);
		if ((!ft_isalpha(name[i]) && !ft_isalnum(name[i])) && i > 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_join_with_equal_char(char **name_value, char *str)
{
	char	*buff;

	buff = name_value[0];
	name_value[0] = ft_strjoin(buff, str);
	free(buff);
	return (1);
}

int	ft_size_list(t_envs *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

char	*ft_my_getenv(char *name, t_envs *env)
{
	t_envs	*list;

	list = ft_get_by_name(name, env);
	if (list)
	{
		return (list->value);
	}
	return (NULL);
}
