/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlizzie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:17:51 by mlizzie           #+#    #+#             */
/*   Updated: 2021/08/21 10:19:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*cutQuote(char *line, int pos1, int pos2)
{
	int		size;
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	size = ft_strlen(line) - 1;
	str = malloc(sizeof(char) * size);
	if (!str)
		return (line);
	str[size - 1] = '\0';
	while (line[++i])
	{
		if (i == pos1 || i == pos2)
			continue ;
		str[j] = line[i];
		j++;
	}
	free(line);
	return (str);
}

char	*parsQuote(char *line, int *i, char quote)
{
	int		j;
	char	*str;

	j = *i;
	while (line[++(*i)])
		if (line[*i] == quote)
			break ;
	str = cutQuote(line, j, *i);
	*i = *i - 2;
	return (str);
}

t_token	*checkPipeAfterRed(t_token	*token)
{
	t_token	*token1;
	t_token	*tokenTop;

	tokenTop = token;
	if (token)
		token1 = token->next;
	while (token && token1)
	{
		if (token->redOrPipe && token1->redOrPipe)
		{
			if ((token->str[0] == '<' || token->str[0] == '>') && \
			 token1->str[0] == '|')
			{
				free_token(&tokenTop);
				outputError("syntax error near unexpected token'|'", NULL, 258);
				return (NULL);
			}
		}
		token = token->next;
		token1 = token->next;
	}
	return (tokenTop);
}

void	getKeyEnv(t_token *token, t_envs *env)
{
	char	*copyStr;

	while (token)
	{
		copyStr = token->str;
		token->str = replacementKeyEnv(token->str, env);
		if (!(token->str))
			free(copyStr);
		token = token->next;
	}
}

t_token	*checkToken(t_token *token, char *line)
{
	t_token	*top;

	free(line);
	top = token;
	while (token)
	{
		if (!token->str)
		{
			free_token(&top);
			outputError("error malloc", NULL, 128);
			return (NULL);
		}
		token = token->next;
	}
	return (top);
}
