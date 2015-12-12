/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 11:48:33 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/27 13:42:46 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int			is_path(char *cmd)
{
	char	*trim;

	trim = ft_strtrim(cmd);
	if (trim[0] == '.' || trim[0] == '~' || trim[0] == '/'
						|| ft_strchr(cmd, '/') != NULL)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char		**get_valid_path(t_list *list_env)
{
	char	*ret;

	if ((ret = find_content_list(list_env, "PATH")) != NULL)
	{
		return (ft_strsplit(ret, ':'));
	}
	else
	{
		ret = find_old_content_list(list_env, "PATH");
		return (ft_strsplit(ret, ':'));
	}
}

int			is_binary(char **cmd, t_list **list_env)
{
	int		acs;

	acs = access(cmd[0], F_OK);
	if (acs == 0)
	{
		acs = access(cmd[0], X_OK);
		if (acs == 0)
		{
			if (execve(cmd[0], cmd, make_env(*list_env)) < 0)
			{
				return (-1);
			}
			else
			{
				return (1);
			}
		}
		else
			return (-1);
	}
	else
	{
		permission_ok(cmd[0]);
		return (-1);
	}
}

char		*found_path(char *cmd, char **path)
{
	char	*final_path;
	int		i;
	int		acs;

	i = 0;
	while (path[i])
	{
		final_path = ft_strjoin(path[i], "/");
		final_path = ft_strjoin(final_path, cmd);
		if ((acs = access(final_path, F_OK)) == 0)
		{
			if ((acs = access(final_path, X_OK)) == 0)
			{
				return (final_path);
			}
		}
		i++;
	}
	return (NULL);
}
