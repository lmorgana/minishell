/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertTokenInExc_utils1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlizzie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:17:07 by mlizzie           #+#    #+#             */
/*   Updated: 2021/08/21 10:19:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	countToken(t_token *token)
{
	int	i;

	i = 0;
	while (token)
	{
		i++;
		token = token->next;
	}
	return (i);
}

void	*free_exc(t_exc *exc, int size)
{
	int	i;

	i = 0;
	while (size != i)
	{
		free(exc[i].flags);
		i++;
	}
	return (NULL);
}

char	**initFlags(char **flags, int size)
{
	while (size)
	{
		flags[size] = NULL;
		size--;
	}
	return (flags);
}

t_exc	*initArray(int size, t_exc *exc)
{
	int	i;

	i = 0;
	while (i != size)
	{
		exc[i].name = NULL;
		exc[i].path_bin = NULL;
		exc[i].flags = NULL;
		exc[i].flags = malloc(sizeof(char *) * (size + 1));
		if (!(exc[i].flags))
			return (free_exc(exc, i));
		exc[i].flags = initFlags(exc[i].flags, size);
		exc[i].pipe_stat[0] = 0;
		exc[i].pipe_stat[1] = 0;
		exc[i].pipe[0] = 0;
		exc[i].pipe[1] = 1;
		exc[i].type = 0;
		exc[i].ch_pid = -1;
		exc[i].stopWord = NULL;
		exc[i].checkComnd = 0;
		exc[i].inFd = 0;
		exc[i].outFd = 0;
		i++;
	}
	return (exc);
}

int	getTypeComand(char *str)
{
	if (str && str[0] == 'e' && str[1] == 'c' && \
	 str[2] == 'h' && str[3] == 'o' && str[4] == '\0')
		return (2);
	if (str && str[0] == 'c' && str[1] == 'd' && str[2] == '\0')
		return (2);
	if (str && str[0] == 'p' && str[1] == 'w' && \
	 str[2] == 'd' && str[3] == '\0')
		return (2);
	if (str && str[0] == 'e' && str[1] == 'x' && str[2] == 'p' && \
	 str[3] == 'o' && str[4] == 'r' && str[5] == 't' && str[6] == '\0')
		return (2);
	if (str && str[0] == 'u' && str[1] == 'n' && str[2] == 's' && \
	 str[3] == 'e' && str[4] == 't' && str[5] == '\0')
		return (2);
	if (str && str[0] == 'e' && str[1] == 'n' && str[2] == 'v' && \
	 str[3] == '\0')
		return (2);
	if (str && str[0] == 'e' && str[1] == 'x' && str[2] == 'i' && \
	 str[3] == 't' && str[4] == '\0')
		return (2);
	return (1);
}
