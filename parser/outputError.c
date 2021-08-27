/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputError.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlizzie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:18:33 by mlizzie           #+#    #+#             */
/*   Updated: 2021/08/20 13:04:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*outputError(char *str, char *line, int exit_status)
{
	printf("\033[0;31m\033[1mms:\033[0m");
	printf(" %s\n", str);
	if (line)
		free(line);
	g_exit_status.curr = exit_status;
	return (NULL);
}
