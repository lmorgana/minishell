/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:59:12 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 10:59:15 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_envs	*ft_create_elem(char *name, char *value)
{
	t_envs	*new;

	new = malloc(sizeof (t_envs));
	if (new)
	{
		new->name = name;
		new->value = value;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

t_envs	*ft_get_last_lst(t_envs *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

int	ft_back_to_lst(char *name, char *value, t_envs **list)
{
	t_envs	*last;
	t_envs	*new;

	if (*list == NULL)
	{
		*list = ft_create_elem(name, value);
		if (!*list)
			return (0);
	}
	else
	{
		last = ft_get_last_lst(*list);
		new = ft_create_elem(name, value);
		if (new)
			last->next = new;
	}
	return (1);
}

t_envs	*ft_create_lists_from_env(char **env)
{
	t_envs	*list;
	int		i;
	char	**name_value;

	i = 0;
	list = NULL;
	while (env[i])
	{
		name_value = ft_split(env[i], '=');
		if (!name_value)
			return (0);
		if (ft_is_equal(name_value[0], "SHLVL"))
			ft_increase_shlvl(&name_value[1]);
		if (name_value[1] != 0 || ft_strchr(env[i], '='))
			ft_join_with_equal_char(name_value, "=");
		if (!name_value || !ft_back_to_lst(name_value[0], name_value[1], &list))
		{
			ft_clear_env(list);
			return (0);
		}
		free(name_value);
		i++;
	}
	return (list);
}

char	**list_into_char(t_envs *list)
{
	int		len;
	int		i;
	char	**arr;

	len = ft_size_list(list);
	arr = malloc(sizeof (char *) * (len + 1));
	i = 0;
	while (list)
	{
		if (list->value == NULL)
			list->value = "";
		arr[i] = ft_strjoin(list->name, list->value);
		if (arr[i] == NULL)
		{
			ft_clear_arr(arr);
			return (0);
		}
		i++;
		list = list->next;
	}
	arr[i] = NULL;
	return (arr);
}
