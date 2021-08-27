/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_our_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:46:27 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/21 10:19:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_del_from_list(char *name, t_envs *list)
{
	t_envs	*elem;
	t_envs	*next_elem;

	if (ft_is_name_valid(name))
	{
		elem = ft_get_by_name(name, list);
		if (elem)
		{
			free(elem->name);
			free(elem->value);
			next_elem = elem->next;
			if (next_elem)
			{
				elem->name = next_elem->name;
				elem->value = next_elem->value;
				elem->next = next_elem->next;
			}
			free(next_elem);
		}
	}
	return (0);
}

int	ft_our_unset(t_exc *arg, t_conf *conf)
{
	int	i;

	i = 1;
	while (arg->flags[i])
	{
		ft_del_from_list(arg->flags[i], conf->env);
		i++;
	}
	return (0);
}
