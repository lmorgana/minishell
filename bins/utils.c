/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:43:34 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_is_equal(char *str1, char *str2)
{
	if (str1 && str2)
	{
		if (ft_strncmp(str1, str2, ft_strlen(str1)) == 0
			&& ft_strlen(str1) == ft_strlen(str2))
			return (1);
	}
	return (0);
}

int	ft_clear_exc(t_exc *args)
{
	int	i;

	i = 0;
	while (args[i].name)
	{
		if (args[i].path_bin)
			free(args[i].path_bin);
		i++;
	}
	return (1);
}

char	*ft_is_path_exist(char *path)
{
	struct stat	buff;

	if (stat(path, &buff) == -1)
		return (NULL);
	return (path);
}
