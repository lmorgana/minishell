/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_our_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 00:20:58 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/21 00:20:59 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static	int	ft_is_numeric_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static	int	ft_if_is_one(int is_first_num, char *num, int stat)
{
	if (is_first_num)
	{
		if (stat)
			ctrl_D_hook(123);
	}
	else
	{
		printf("exit\nms: exit: %s: numeric argument required\n", num);
		if (stat)
			exit(1);
	}
	return (1);
}

static	int	ft_if_is_more(int is_first_num, char *first, int stat)
{
	if (is_first_num)
	{
		printf("exit\nms: exit: too many arguments\n");
		g_exit_status.curr = 1;
	}
	else
	{
		printf("exit\nms: exit: %s: numeric argument required\n", first);
		if (stat)
			exit(1);
	}
	return (1);
}

int	ft_our_exit(t_exc *arg)
{
	int		i;
	int		is_first_num;
	char	*first;

	i = 1;
	is_first_num = 0;
	while (arg->flags[i])
	{
		if (i == 1 && ft_is_numeric_str(arg->flags[i]))
			is_first_num = 1;
		if (i == 1)
			first = arg->flags[i];
		i++;
	}
	if (i == 1 && arg->pipe[0] == 0 && arg->pipe[1] == 1)
		ctrl_D_hook(12);
	else if (i == 2)
		ft_if_is_one(is_first_num, arg->flags[0], \
		(arg->pipe[0] == 0 && arg->pipe[1] == 1));
	else if (i > 2)
		ft_if_is_more(is_first_num, first, \
		(arg->pipe[0] == 0 && arg->pipe[1] == 1));
	return (1);
}
