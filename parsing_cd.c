/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 15:14:02 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/30 15:49:22 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int			cd_check_flag_all(char c, t_cd_options *options)
{
	if (c == 'L')
	{
		options->options_l = 1;
		options->options_p = 0;
	}
	else if (c == 'P')
	{
		options->options_l = 0;
		options->options_p = 1;
	}
	else
		return (-1);
	return (1);
}

int			cd_read_flag_base(char *argument, t_cd_options *options)
{
	int i;

	i = 1;
	while (argument[i])
	{
		if (cd_check_flag_all(argument[i], options) == -1)
			return (-1);
		i++;
	}
	return (1);
}

int			cd_read_argv(char *argument, t_cd_options *options)
{
	if (argument[0] == '-' && argument[1] != '\0' && argument[1] != '-')
	{
		if (cd_read_flag_base(argument, options) == -1)
		{
			return (ft_error("cd: no such file or directory: ",
						argument, "\n"));
		}
		return (1);
	}
	return (0);
}

char		**ft_parse_cd(char **argv, t_cd_options *options)
{
	int i;
	int len;
	int result;

	len = ft_strtab_len(argv);
	i = 1;
	while (argv[i])
	{
		result = cd_read_argv(argv[i], options);
		if (result == 0)
			break ;
		else if (result == -1)
			return (NULL);
		i++;
	}
	options->nb_flag = i - 1;
	options->nb_arg_real = len - options->nb_flag - 1;
	return (argv);
}
