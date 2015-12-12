/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 11:48:33 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/30 17:42:55 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void				ft_replace_double_minus(t_list *list_env,
						char **path, int index)
{
	char			*tmp;

	if (ft_strcmp(path[index], "--") == 0)
	{
		if (path[index + 1])
		{
			tmp = ft_strdup(path[index + 1]);
			path[index] = tmp;
		}
		else
		{
			tmp = ft_strcut(path[index], 2, 10000);
			path[index] = ft_strjoin(find_content_list(list_env, "HOME"), tmp);
		}
	}
}

int					path_ok(char *path)
{
	if (access(path, F_OK) == 0)
	{
		if (access(path, X_OK) != 0 && get_file_type(path) == 'd')
			return (ft_error("Permission denied : ", path, "\n"));
	}
	else
		return (ft_error(path, " : no such file or directory.\n", NULL));
	return (1);
}

int					exec_cd(t_list **list_env, char *path, int flag)
{
	if (path == NULL)
		return (ft_error("no such file or directory.\n", NULL, NULL));
	if (path_ok(path) == -1)
		return (-1);
	ft_update_pwd(list_env, path, flag);
	if (chdir(find_content_list(*list_env, "PWD")) != 0)
		return (ft_error("chdir: no such file or directory.\n", NULL, NULL));
	return (1);
}

void				check_double_minus(char **path, int nb_flag,
							t_list **list_env)
{
	if (ft_strcmp(path[1 + nb_flag], "--") == 0)
		ft_replace_double_minus(*list_env, path, nb_flag + 1);
}

int					ft_cd(char **cmd, t_list **list_env)
{
	char			**path;
	t_cd_options	*options;

	options = init_cd_option();
	if ((path = ft_parse_cd(cmd, options)) == NULL)
		return (-1);
	if (options->nb_arg_real == 0)
	{
		return (exec_cd(list_env, find_content_list(*list_env, "HOME"),
			options->options_p));
	}
	check_double_minus(path, options->nb_flag, list_env);
	if (ft_strcmp(path[1 + options->nb_flag], "-") == 0)
		return (exec_cd(list_env, find_content_list(*list_env, "OLDPWD"),
			options->options_p));
	else if (get_file_type(path[options->nb_flag + 1]) != 'd' &&
				access(path[options->nb_flag + 1], F_OK) == 0)
		return (ft_error("not a directory:\n", NULL, NULL));
	if (permission_ok(path[options->nb_flag + 1]) == 1)
	{
		return (exec_cd(list_env, path[options->nb_flag + 1],
			options->options_p));
	}
	return (1);
}
