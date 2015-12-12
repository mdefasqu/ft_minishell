/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_permission.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 14:29:45 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/27 14:29:48 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char		*init_path(char *cmd, char **sources)
{
	char	*path;

	if (cmd == NULL)
		return (NULL);
	if (cmd[0] == '/')
	{
		path = (char*)malloc(sizeof(char) * 2);
		path[0] = '/';
		path[1] = '\0';
		path = ft_strjoin(path, sources[0]);
	}
	else
		path = sources[0];
	return (path);
}

int			permission_ok(char *cmd)
{
	int		i;
	char	*path;
	char	**sources;

	i = 0;
	sources = ft_strsplit(cmd, '/');
	if ((path = init_path(cmd, sources)) == NULL)
		return (-1);
	if (ft_strcmp(cmd, "chmod") == 0)
		return (1);
	while (i < (int)ft_strtab_len(sources))
	{
		if (access(path, F_OK) == 0)
		{
			if (access(path, X_OK) != 0 && get_file_type(path) == 'd')
				return (ft_error("Permission denied : ", path, "\n"));
		}
		else
			return (ft_error(path, " : no such file or directory.\n", NULL));
		i++;
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, sources[i]);
	}
	return (1);
}
