/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlizzie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:18:48 by mlizzie           #+#    #+#             */
/*   Updated: 2021/08/20 13:04:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	*free_token(t_token **top)
{
	t_token	*ptr;
	t_token	*copy;

	ptr = *top;
	while (ptr)
	{
		copy = ptr->next;
		if (ptr->str)
			free(ptr->str);
		free(ptr);
		ptr = copy;
	}
	*top = NULL;
	return (NULL);
}

void	createToken(t_token **token, char *str, int redOrPipe)
{
	t_token	*ptr;
	t_token	*new;

	new = malloc (sizeof(*new));
	if (!(new))
	{
		free_token(token);
		return ;
	}
	new->str = str;
	new->redOrPipe = redOrPipe;
	new->next = NULL;
	ptr = *token;
	if (!ptr)
		*token = new;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}
