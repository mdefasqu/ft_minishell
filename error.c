/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 15:50:29 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/27 11:52:57 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	ft_error_parse_env(char c)
{
	ft_putstr_fd("env: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: env [-i] [name=value ...] ", 2);
	ft_putstr_fd("[utility [argument ...]]\n", 2);
}

int		ft_error(const char *str1, const char *str2,
			const char *str3)
{
	if (str1 != NULL)
		ft_putstr_fd(str1, 2);
	if (str2 != NULL)
		ft_putstr_fd(str2, 2);
	if (str3 != NULL)
		ft_putstr_fd(str3, 2);
	return (-1);
}
