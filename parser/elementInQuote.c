/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementInQuote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlizzie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:18:56 by mlizzie           #+#    #+#             */
/*   Updated: 2021/08/21 10:19:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	elementInQuote(char *line, int i, int quoteD)
{
	int		j;
	char	c;

	j = -1;
	c = ' ';
	while (line[++j])
	{
		if (line[j] == '"' && c != '\'' && quoteD)
		{
			if (c != '"')
				c = '"';
			else
				c = ' ';
		}
		if (line[j] == '\'' && c != '"' )
		{
			if (c != '\'')
				c = '\'';
			else
				c = ' ';
		}
		if (i == j && c != ' ')
			return (1);
	}
	return (0);
}

int	inQuoteS(char *line, int i)
{
	int		j;
	char	c;

	j = -1;
	c = ' ';
	while (line[++j])
	{
		if (line[j] == '"' && c != '\'')
		{
			if (c != '"')
				c = '"';
			else
				c = ' ';
		}
		if (line[j] == '\'' && c != '"' )
		{
			if (c != '\'')
				c = '\'';
			else
				c = ' ';
		}
		if (i == j && (c != ' ' && c != '"'))
			return (1);
	}
	return (0);
}
