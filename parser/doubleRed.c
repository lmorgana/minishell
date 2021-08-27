/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubleRed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlizzie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:25:36 by mlizzie           #+#    #+#             */
/*   Updated: 2021/08/21 10:19:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_double_red_ch(int *our_pipe, t_token *token)
{
	char	*line;

	line = NULL;
	while (ft_is_equal(line, token->str) != 1)
	{
		if (line)
		{
			write(our_pipe[1], line, ft_strlen(line));
			write(our_pipe[1], "\n", 1);
			free(line);
		}
		write(1, "> ", 2);
		if ((get_next_line(0, &line) < 0))
		{
			return (-1);
		}
		if (line[0] == '\0')
		{
			write(1, "\n", 1);
			break ;
		}
	}
	if (line)
		free(line);
	return (1);
}

int	ft_double_Red(t_token *token)
{
	int	our_pipe[2];

	signal(SIGINT, &ctrl_for_redirec);
	if (pipe(our_pipe) < 0)
		return (-1);
	ft_double_red_ch(our_pipe, token);
	close(our_pipe[1]);
	signal(SIGINT, &ctrl_c_hook);
	return (our_pipe[0]);
}
