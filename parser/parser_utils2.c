/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlizzie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:18:00 by mlizzie           #+#    #+#             */
/*   Updated: 2021/08/20 18:12:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*getKey(char *line, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (end - start));
	if (!str)
		return (str);
	start++;
	while (start != end)
	{
		str[i] = line[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*getNewLine(char *line, char *strKey, int start, int end)
{
	char	*newLine;
	int		i;
	int		j;

	i = -1;
	newLine = malloc(sizeof(char) * (ft_strlen(line) - \
	(end - start) + 1 + ft_strlen(strKey)));
	if (!newLine)
		return (newLine);
	while (++i != start)
		newLine[i] = line[i];
	j = -1;
	i--;
	if (end == 1)
		end++;
	while (strKey && strKey[++j] && (++i || i == 0))
		newLine[i] = strKey[j];
	end--;
	while (line[++end] && (++i || i == 0))
		newLine[i] = line[end];
	newLine[++i] = '\0';
	free(line);
	if (line[start + 1] == '?' && strKey)
		free(strKey);
	return (newLine);
}

char	*replacementKeyEnv(char *line, t_envs *env)
{
	char	*str;
	int		i;
	char	*strKey;
	int		start;

	i = -1;
	while (line && line[++i])
	{
		if (line[i] == '$' && !(inQuoteS(line, i)) && !(ft_isdigit(line[i + 1]) \
		 || (line[i + 1] == ' ') || (line[i + 1] == '\0')))
		{
			start = i;
			while ((ft_isalnum(line[++i]) || (line[i] == '_')) && line[i])
				;
			str = getKey(line, start, i);
			if (!str)
				return (NULL);
			strKey = ft_my_getenv(str, env);
			free(str);
			if (line[i] == '?' && line[i - 1] == '$' && ++i)
				strKey = ft_itoa(g_exit_status.prev);
			line = getNewLine(line, strKey, start, i);
		}
	}
	return (line);
}

void	clear_memory(t_token **token, t_exc *exc)
{
	int		size;
	t_token	*token1;

	if (exc)
	{
		size = countToken(*token);
		while (size > -1)
		{
			free(exc[size].flags);
			size--;
		}
		free(exc);
	}
	while (*token)
	{
		token1 = *token;
		if ((*token)->str)
			free((*token)->str);
		(*token) = (*token)->next;
		free(token1);
	}
	*token = NULL;
}
