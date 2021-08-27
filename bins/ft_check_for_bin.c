/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_for_bin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:43:07 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/21 10:19:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (1);
}

char	*ft_strjoin_path(char const *s1, char const *s2)
{
	int		i;
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		str = malloc((len_s1 + len_s2 + 2) * sizeof(char));
		if (str)
		{
			i = ft_strlcpy(str, s1, len_s1 + 1);
			str[i] = '/';
			i++;
			ft_strlcpy(&str[i], s2, len_s2 + 1);
			return (str);
		}
	}
	return (NULL);
}

static	char	*ft_is_dir_exist(char *buff, char *name_bin)
{
	DIR				*current_dir;
	struct dirent	*dir_path;

	current_dir = opendir(buff);
	if (current_dir)
	{
		while (1)
		{
			dir_path = readdir(current_dir);
			if (dir_path == NULL)
				break ;
			if (ft_is_equal(dir_path->d_name, name_bin))
			{
				closedir(current_dir);
				return (ft_strjoin_path(buff, name_bin));
			}
		}
		closedir(current_dir);
	}
	return (0);
}

static	char	*ft_check_each(char *all_paths, char *name_bin)
{
	char	**lst_paths;
	int		i;
	char	*path;

	(void) name_bin;
	lst_paths = ft_split(all_paths, ':');
	if (lst_paths)
	{
		i = 0;
		while (lst_paths[i])
		{
			path = ft_is_dir_exist(lst_paths[i], name_bin);
			if (path)
			{
				ft_free_arr(lst_paths);
				return (path);
			}
			i++;
		}
		ft_free_arr(lst_paths);
	}
	return (0);
}

char	*ft_check_for_bin(char *name_bin, t_conf *conf)
{
	char	*all_paths;
	char	*path_of_bin;

	(void) name_bin;
	all_paths = ft_my_getenv("PATH", conf->env);
	if (all_paths)
	{
		path_of_bin = ft_check_each(all_paths, name_bin);
		if (path_of_bin)
			return (path_of_bin);
	}
	return (0);
}
