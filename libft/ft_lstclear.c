/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 21:23:15 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{	
	t_list	*n;

	if (lst && del)
	{
		if (*lst)
		{
			while ((*lst)->next)
			{
				n = (*lst)->next;
				ft_lstdelone(*lst, del);
				*lst = n;
			}
			if ((*lst)->next == NULL)
				ft_lstdelone(*lst, del);
			*lst = NULL;
		}
	}
}
