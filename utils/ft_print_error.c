/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:46:44 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/20 13:04:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_print_error(char *str, char *code_of_error)
{
	char	*err_msg;

	write(2, "ms: ", 4);
	if (str)
		write(2, str, ft_strlen(str));
	write(2, ": ", 3);
	if (code_of_error)
		err_msg = code_of_error;
	else
		err_msg = strerror(errno);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n", 1);
	return (0);
}
