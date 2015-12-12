/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 14:46:13 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/30 15:45:58 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char		*tab_to_str(char **tab, char c, int begin)
{
	int		i;
	char	*ret;

	i = begin;
	while (tab[i])
	{
		ret = ft_strjoin(ret, tab[i]);
		ret = ft_strjoin(ret, &c);
		i++;
	}
	return (ret);
}

char		*list_to_str(t_list *list, const char *c)
{
	char	*ret;

	if (list->titre[0] == '/')
		ret = NULL;
	else
		ret = ft_strdup("/");
	while (list)
	{
		ret = ft_strjoin(ret, list->titre);
		if (list->next && ft_strcmp(list->titre, "/") != 0)
			ret = ft_strjoin(ret, c);
		list = list->next;
	}
	return (ret);
}

t_list		*set_old(char *path, char *oldpwd)
{
	if (path[0] == '/')
		return (new_list_item_fill("/", NULL, NULL, 1));
	else
		return (ft_make_list(oldpwd));
}

char		*parse_pwd_path(char *path, char *oldpwd)
{
	int		i;
	char	**step;
	t_list	*old;

	if (oldpwd == NULL || path == NULL)
		return (NULL);
	old = set_old(path, oldpwd);
	step = ft_strsplit(path, '/');
	i = 0;
	while (step[i])
	{
		if (ft_strcmp(step[i], ".") == 0)
			;
		else if (ft_strcmp(step[i], "..") == 0)
		{
			if (ft_len_list(old) <= 1)
				return (ft_strdup("/"));
			remove_last(&old);
		}
		else
			add_to_list(&old, new_list_item_fill(step[i], NULL, NULL, 1));
		i++;
	}
	return (list_to_str(old, "/"));
}

int			ft_update_pwd(t_list **list_env, char *new_path, int flag)
{
	char	*valid_path;
	char	buf[512];

	if (flag == 1)
		valid_path = getcwd(buf, 512);
	else
		valid_path = parse_pwd_path(new_path,
			ft_strdup(find_content_list(*list_env, "PWD")));
	if (valid_path == NULL)
		valid_path = getcwd(buf, 512);
	update_content_list(list_env, "OLDPWD",
		find_content_list(*list_env, "PWD"));
	update_content_list(list_env, "PWD", valid_path);
	update_content_list(list_env, "CDEXSWZAQ", valid_path);
	return (0);
}
