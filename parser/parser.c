/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlizzie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:17:38 by mlizzie           #+#    #+#             */
/*   Updated: 2021/08/21 10:19:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	parserPipe(t_token **token, char *line, int j, int i)
{
	if (i != j)
		createToken(token, ft_substr(line, j, i - j), 0);
	 createToken(token, ft_strdup("|"), 1);
	return (i + 1);
}

int	parserRed(t_token **token, char *line, int j, int *i)
{
	if (*i != j && *i > j)
		createToken(token, ft_substr(line, j, *i - j), 0);
	if (line[*i] == '<')
	{
		if (line[*i + 1] == '<')
			createToken(token, ft_strdup("<<"), 1);
		else
			createToken(token, ft_strdup("<"), 1);
	}
	 if (line[*i] == '>')
	{
		if (line[*i + 1] == '>')
			createToken(token, ft_strdup(">>"), 1);
		else
			createToken(token, ft_strdup(">"), 1);
	}
	if (line[*i + 1] == '<' || line[*i + 1] == '>')
	{
		(*i)++;
		return (*i + 1);
	}
	return (*i + 1);
}

int	parserSpace(t_token **token, char *line, int j, int i)
{
	if (i != j)
		createToken(token, ft_substr(line, j, i - j), 0);
	return (i + 1);
}

void	deleteQuote(t_token *token)
{
	int	i;

	while (token)
	{
		i = 0;
		while (token->str[i])
		{
			if (token->str[i] == '"')
				token->str = parsQuote(token->str, &i, '"');
			else if (token->str[i] == '\'')
				token->str = parsQuote(token->str, &i, '\'');
			if (!token->str[i])
				break ;
			i++;
		}	
		token = token->next;
	}
}

t_token	*parser(char *line, t_envs *env)
{
	int		i;
	int		j;
	t_token	*token;

	token = NULL;
	i = -1;
	j = 0;
	line = preparser(line);
	if (!line)
		return (NULL);
	while (line[++i])
	{
		if (line[i] == '|' && !(elementInQuote(line, i, 1)))
			j = parserPipe(&token, line, j, i);
		if ((line[i] == '<' || line[i] == '>') && !(elementInQuote(line, i, 1)))
			j = parserRed(&token, line, j, &i);
		if (line[i] == ' ' && !(elementInQuote(line, i, 1)))
			j = parserSpace(&token, line, j, i);
	}
	if (i != 0)
		createToken(&token, ft_substr(line, j, i - j), 0);
	getKeyEnv(token, env);
	deleteQuote(token);
	token = checkPipeAfterRed(token);
	return (checkToken(token, line));
}
