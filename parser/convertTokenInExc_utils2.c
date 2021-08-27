/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertTokenInExc_utils2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlizzie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:17:19 by mlizzie           #+#    #+#             */
/*   Updated: 2021/08/20 13:04:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_token	*initFlagss(t_token *token, t_exc *exc, int i)
{
	int	j;

	j = 1;
	if ((exc[i].name[0] == '>' || exc[i].name[0] == '<') && exc[i].checkComnd)
	{
		exc[i].name = token->str;
		exc[i].checkComnd = 0;
		return (token->next);
	}
	while (exc[i].flags[j])
		j++;
	exc[i].flags[j] = token->str;
	return (token->next);
}

void	writeFd(int inFd, int outFd, t_exc *exc, int i)
{
	if (inFd != 0)
	{
		if (exc[i].inFd)
			close(exc[i].inFd);
		exc[i].inFd = inFd;
	}
	else if (outFd != 0)
	{
		if (exc[i].outFd)
			close(exc[i].outFd);
		exc[i].outFd = outFd;
	}
}

t_token	*initFd(t_token *token, t_exc *exc, int i)
{
	int		inFd;
	int		outFd;
	t_token	*tokenNext;

	inFd = 0;
	outFd = 0;
	tokenNext = token->next;
	if (exc[i].inFd == -1 || exc[i].outFd == -1)
		return (tokenNext->next);
	if (token->str[0] == '>' && token->str[1] == '>')
		outFd = open(tokenNext->str, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (token->str[0] == '>' && token->str[1] == '\0')
		outFd = open(tokenNext->str, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (token->str[0] == '<' && token->str[1] == '\0')
		inFd = open(tokenNext->str, O_RDONLY, 0777);
	if (token->str[0] == '<' && token->str[1] == '<')
		inFd = ft_double_Red(tokenNext);
	if (inFd == -1 || outFd == -1)
	{
		g_exit_status.curr = 126;
		printf("ms: %s: No such file or dirnectory\n", tokenNext->str);
	}
	writeFd(inFd, outFd, exc, i);
	return (tokenNext->next);
}

t_token	*writeRedInExc(t_exc *exc, int i, t_token *token)
{
	while (token && !(token->str[0] == '|' && token->redOrPipe))
	{
		if (token->redOrPipe)
			token = initFd(token, exc, i);
		else
			token = initFlagss(token, exc, i);
	}
	return (token);
}
