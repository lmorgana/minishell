/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait_for_all_pids.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:43:49 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 18:12:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_wait_for_all_pids(t_exc *argv)
{
	int	i;
	int	stat_ch;

	i = 0;
	while (argv[i].name)
	{
		if (argv[i].ch_pid == -1)
			i++;
		waitpid(argv[i].ch_pid, &stat_ch, 0);
		i++;
	}
	if (i > 0)
		i--;
	if (argv[i].ch_pid != -1 && WIFEXITED(stat_ch))
	{
		if (WEXITSTATUS(stat_ch) != 0)
		{
			if (g_exit_status.curr == 0)
				g_exit_status.curr = 127;
			return (0);
		}
	}
	return (1);
}
