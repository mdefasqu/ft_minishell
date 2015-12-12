/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 17:09:12 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/30 17:09:13 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int			read_flag_base(char *argument, t_options *options)
{
	int i;

	i = 1;
	while (argument[i])
	{
		if (check_flag_all(argument[i], options) < 0)
			return (-1);
		i++;
	}
	return (1);
}

int			read_argv(char *argument, t_options *options)
{
	if (argument[0] == '-' && argument[1] != '\0' && argument[1] != '-')
	{
		if (read_flag_base(argument, options) < 0)
			return (-1);
		return (1);
	}
	return (0);
}

void		check_equal_argv(char **argv, t_options *options)
{
	int i;
	int y;

	i = options->nb_flag + 1;
	while (argv[i])
	{
		y = 0;
		while (argv[i][y])
		{
			if (argv[i][y] == '=')
				break ;
			else
				y++;
		}
		if (argv[i][y] != '=')
			break ;
		else
			i++;
	}
	options->nb_equal = i - (options->nb_flag + 1);
}

void		parse_env_2(char ***argv, int *argc, int i, t_options *options)
{
	int y;

	y = 2;
	while ((*argv)[i][y])
	{
		if ((*argv)[i][y] != '-')
		{
			ft_error_parse_env((*argv)[i][y]);
			options->error = -1;
			break ;
		}
		y++;
	}
	*argv = del_one_argv(*argv, i);
	(*argc)--;
}

char		**parse_env(char **argv, t_options *options, int argc)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (read_argv(argv[i], options) == 0)
		{
			if (argv[i][0] == '-' && argv[i][1] == '-')
				parse_env_2(&argv, &argc, i, options);
			break ;
		}
		i++;
	}
	options->nb_flag = i - 1;
	while (argv[i])
		i++;
	options->nb_arg_real = argc - options->nb_flag - 1;
	check_equal_argv(argv, options);
	options->nb_command = options->nb_arg_real - options->nb_equal;
	return (argv);
}
