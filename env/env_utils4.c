/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:45:04 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 10:45:06 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_increase_shlvl(char **shlvl_a)
{
	int	shlvl_i;

	shlvl_i = ft_atoi(*shlvl_a);
	if (shlvl_i > 0)
	{
		shlvl_i++;
		free(*shlvl_a);
		*shlvl_a = ft_itoa(shlvl_i);
		return (1);
	}
	return (0);
}
