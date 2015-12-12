/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:59:50 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/29 12:59:51 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int			no_char(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1 || str[0] == '-')
			i++;
		else if (ft_isdigit(str[i]) == 0 && i > 0)
		{
			ft_error("exit: Badly formed number.\n", NULL, NULL);
			return (-1);
		}
		else
			return (3);
	}
	return (2);
}

int			ft_exit_value(char **cmd)
{
	int i;

	i = ft_strtab_len(cmd);
	if (i == 2)
		i = no_char(cmd[1]);
	if (i == 1)
		exit(0);
	else if (i == 2)
	{
		i = ft_atoi(cmd[1]);
		if (i >= 0 && i <= 256)
			exit(i);
		if (i > 256)
			exit(i % 256);
		if (i < -256)
		{
			i = i * -1;
			exit(256 - (i % 256));
		}
		if (i < 0 && i >= -256)
			exit(256 + i);
	}
	else if (i > 2)
		ft_error("exit: Expression Syntax.\n", NULL, NULL);
	return (1);
}
