/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 11:57:41 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/29 17:33:24 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int			exec_builtin(char **cmd, t_list **list_env)
{
	if (ft_strcmp(cmd[0], "env") == 0)
		return (ft_env(cmd, *list_env));
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
		return (ft_unsetenv(cmd, list_env));
	else if (ft_strcmp(cmd[0], "cd") == 0)
		return (ft_cd(cmd, list_env));
	else if (ft_strcmp(cmd[0], "setenv") == 0)
		return (ft_setenv(cmd, list_env));
	else if (ft_strcmp(cmd[0], "exit") == 0)
		return (ft_exit_value(cmd));
	else if (ft_strcmp(cmd[0], "star_wars") == 0)
		return (ft_star_wars(cmd, list_env));
	else if (ft_strcmp(cmd[0], "bonus") == 0)
		return (ft_bonus_tab(cmd));
	else
		return (-2);
}

int			exec_special(char **cmd, t_list **list_env)
{
	if (is_path(cmd[0]) == 1)
	{
		if (is_binary(cmd, list_env) == 1)
			return (1);
		else
		{
			ft_error("Permission denied : ", cmd[0], "\n");
			exit(0);
			return (-1);
		}
	}
	else
		return (-1);
}

int			lunch_cmd(char **cmd, char **path, t_list **list_env)
{
	int		i;
	char	*final_path;

	i = 0;
	if (exec_special(cmd, list_env) > 0)
		return (1);
	else
	{
		while (path[i])
		{
			if ((final_path = found_path(cmd[0], path)) != NULL)
			{
				if (execve(final_path, cmd, make_env(*list_env)) < 0)
					i++;
			}
			else
				i++;
		}
		i = 0;
		return (-1);
	}
}

void		child_fork(char **result, char **path, t_list **list_env)
{
	if (lunch_cmd(result, path, list_env) < 1)
	{
		ft_error("minishell1: command not found: ",
			result[0], "\n");
		exit(0);
	}
}

void		parsing(const char *gnl, t_list **list_env)
{
	char	***result;
	char	**path;
	int		i;
	pid_t	child;

	i = 0;
	path = get_valid_path(*list_env);
	result = ft_clean_param(ft_replace_orig(gnl, list_env));
	if (result == NULL)
		return ;
	while (result[i])
	{
		if (exec_builtin(result[i], list_env) == -2)
		{
			child = fork();
			if (child == 0)
				child_fork(result[i], path, list_env);
			if (child > 0)
				wait(0);
		}
		i++;
	}
	ft_strdel_2d(&path);
	ft_strdel_3d(&result);
}
