/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertTokenInExc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlizzie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:16:25 by mlizzie           #+#    #+#             */
/*   Updated: 2021/08/21 10:19:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_token	*writeComand(t_token *token, t_exc *exc, int i)
{
	if (token->redOrPipe && (token->str[0] == '<' || token->str[0] == '>' ))
	{
		exc[i].name = token->str;
		exc[i].checkComnd = 1;
		return (token);
	}
	else
	{
		exc[i].name = token->str;
		 return (token->next);
	}
}

t_token	*writeflags(t_exc *exc, int i, t_token *token)
{
	int	j;

	j = 1;
	while (token && !token->redOrPipe)
	{
		exc[i].flags[j] = token->str;
		 token = token->next;
		 j++;
	}
	exc[i].flags[j] = NULL;
	return (token);
}

int	getNumRed(t_token *token)
{
	char	*str;

	str = token->str;
	if (str && str[0] == '<' && str[1] == '\0')
		return (1);
	if (str && str[0] == '<' && str[1] == '<')
		return (2);
	if (str && str[0] == '>' && str[1] == '>')
		return (3);
	if (str && str[0] == '>' && str[1] == '\0')
		return (4);
	return (0);
}

t_exc	*detourExc(t_exc *exc)
{
	int	i;

	i = 0;
	while (exc[i].name)
	{
		if ((i > 0) && exc[i - 1].pipe_stat[1])
			exc[i].pipe_stat[0] = 1;
		if ((exc[i].name[0] == '>' || exc[i].name[0] == '<') && \
		exc[i].checkComnd)
			exc[i].name[0] = '\0';
		if (exc[i].flags)
			exc[i].flags[0] = exc[i].name;
		exc[i].type = getTypeComand(exc[i].name);
		i++;
	}
	return (exc);
}

t_exc	*convertTokenInExc(t_token *token)
{
	t_exc	*exc;
	int		i;

	exc = malloc(sizeof(*exc) * ((countToken(token)) + 1));
	if (!exc)
		return (exc);
	i = 0;
	exc = initArray(countToken(token) + 1, exc);
	while (exc && token)
	{
		token = writeComand(token, exc, i);
		while (token && !(token->redOrPipe))
			 token = writeflags(exc, i, token);
		if (token && (token->str[0] == '<' || token->str[0] == '>'))
			token = writeRedInExc(exc, i, token);
		if (token && (token->str[0] == '|'))
		{
			exc[i].pipe_stat[1] = 1;
			token = token->next;
		}
		 i++;
	}
	return (detourExc(exc));
}
