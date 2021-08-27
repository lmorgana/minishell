/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:36:30 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_lstback(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
		*lst = new;
	else if (lst && new)
	{
		last = *lst;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
		return (1);
	}
	return (0);
}

static	void	ft_fill_newlst(t_list *lst, t_list *new_lst, \
	void *(*f)(void *), void (*del)(void *))
{
	while (lst->next)
	{
		if (!ft_lstback(&new_lst, ft_lstnew(f(lst->content))))
			ft_lstclear(&new_lst, del);
		lst = lst->next;
	}
	if (!lst->next)
		if (!ft_lstback(&new_lst, ft_lstnew(f(lst->content))))
			ft_lstclear(&new_lst, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	void	*cont;

	if (!del)
		del = &free;
	if (lst && f)
	{
		cont = f(lst->content);
		if (cont)
		{
			new_lst = ft_lstnew(cont);
			if (new_lst)
			{
				lst = lst->next;
				ft_fill_newlst(lst, new_lst, f, del);
				return (new_lst);
			}
			return (NULL);
		}
		return (NULL);
	}
	return (NULL);
}
