/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlizzie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:18:15 by mlizzie           #+#    #+#             */
/*   Updated: 2021/08/20 13:04:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	searchQuote(char *line, int i, char elem)
{
	while (line[i] != elem && line[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	checkpipe(char *line, int i)
{
	int	j;
	int	ii;

	j = 0;
	while (line[j])
		j++;
	ii = i + 1;
	while (line[ii] == ' ' && line[ii] != '\0')
	{
		 ii++;
	}
	if (line[ii] == '|' || line[ii] == '\0' || i == 0)
		return (j);
	return (i);
}

int	checred(char *line, int i)
{
	int	j;

	j = 0;
	while (line[j])
		j++;
	if (line[i] == '<')
	{
		if ((line[i + 1] == '\0') || line[i + 1] == '>' || (line[i + 2] != \
		 '\0' && (line[i + 2] == '<' || line[i + 2] == '>')))
			return (j);
	}
	 if (line[i] == '>')
	{
		if ((line[i + 1] == '\0') || line[i + 1] == '<' || (line[i + 2] != \
		 '\0' && (line[i + 2] == '<' || line[i + 2] == '>')))
			return (j);
	}
	return (i);
}

char	*deleteSpace(char *line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = -1;
	str = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!str)
		return (str);
	while (line[i] == ' ' && line[i] != '\0')
		i++;
	while (line[i])
	{
		while (line[i] != '\0' && (line[i] == ' ' && line [i + 1] == ' '))
			i++;
		str[++j] = line[i];
		i++;
	}
	free(line);
	if (str[j] == ' ')
		str[j] = '\0';
	else
		str[j + 1] = '\0';
	return (str);
}

char	*preparser(char *line)
{
	int		i;
	char	*copyLine;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			i = searchQuote(line, ++i, '\'');
		if (line[i] == '"')
			i = searchQuote(line, ++i, '"');
		if (line[i] == '|')
			i = checkpipe(line, i);
		if (line[i] == '<' || line[i] == '>')
			i = checred(line, i);
		if (line[i] == '\0')
			return (outputError("syntax error", line, 258));
		i++;
	}
	copyLine = line;
	line = deleteSpace(line);
	if (line)
		return (line);
	else
		return (outputError("error malloc", copyLine, 42));
}
