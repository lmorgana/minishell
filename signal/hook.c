/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlizzie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:33:20 by mlizzie           #+#    #+#             */
/*   Updated: 2021/08/20 19:33:23 by mlizzie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ctrl_c_hook(int sig)
{
	(void) sig;
	g_exit_status.curr = 130;
	rl_on_new_line();
	rl_redisplay();
	write(1, "  \n", 3);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	ctrl_c_hook_for_ch(int sig)
{
	(void) sig;
	g_exit_status.curr = 130;
	write(1, "  \n", 3);
	kill(0, SIGINT);
}

void	ctrl_for_redirec(int sig)
{
	(void) sig;
	rl_replace_line("", 0);
	write(1, "\n> ", 3);
}

void	ctrl_sh(int sig)
{
	(void) sig;
	kill(0, SIGINT);
	g_exit_status.curr = 131;
	ft_putstr_fd("\e[1A\e[2C" "Quit: 3\n", 1);
}

void	ctrl_D_hook(int sig)
{
	(void) sig;
	ft_putstr_fd("\e[1A\e[5C" "exit\n", 1);
	exit(0);
}
