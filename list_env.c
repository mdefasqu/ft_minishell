/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 17:16:43 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/30 12:19:38 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char		*in_shlvl(const char *source)
{
	int		i;
	int		y;
	char	*finish;

	i = 0;
	y = 0;
	while (source[i])
	{
		if (source[i] < '0' || source[i] > '9')
			y = 1;
		i++;
	}
	if (y == 1)
		finish = ft_strdup("1");
	else
	{
		i = ft_atoi(source);
		i++;
		finish = ft_itoa(i);
	}
	return (finish);
}

void		set_balise_2(t_list **list, char *str, char *pwd)
{
	t_list	*tmp;
	t_list	*path;

	tmp = *list;
	if (if_titre_exist(tmp, "PATH") != 1)
	{
		path = new_list_item_fill("PATH", NULL, str, 0);
		add_to_list(list, path);
	}
	if (if_titre_exist(tmp, "PWD") != 1)
	{
		path = new_list_item_fill("PWD", pwd, NULL, 1);
		add_to_list(list, path);
	}
	if (if_titre_exist(tmp, "CDEXSWZAQ") != 1)
	{
		path = new_list_item_fill("CDEXSWZAQ",
			find_content_list(tmp, "PWD"), NULL, 0);
		add_to_list(list, path);
	}
}

void		set_balise(t_list **list)
{
	t_list	*tmp;
	char	*str;
	char	*pwd;
	char	*propre;

	tmp = *list;
	while (tmp)
	{
		if (ft_strcmp(tmp->titre, "QAZWSXEDC") == 0)
			str = tmp->content;
		if (ft_strcmp(tmp->titre, "SHLVL") == 0)
		{
			propre = in_shlvl(tmp->content);
			tmp->content = ft_strdup(propre);
			ft_strdel(&propre);
		}
		if (ft_strcmp(tmp->titre, "CDEXSWZAQ") == 0)
			pwd = tmp->content;
		tmp = tmp->next;
	}
	set_balise_2(list, str, pwd);
	change_active_state(list, "CDEXSWZAQ", 0);
	change_active_state(list, "QAZWSXEDC", 0);
}

t_list		*get_env(char **env)
{
	t_list	*head;
	t_list	*next;
	char	**tmp;
	int		i;

	i = 0;
	head = new_list_item();
	next = head;
	while (env[i])
	{
		tmp = ft_strsplit(env[i], '=');
		next->titre = tmp[0];
		next->content = tmp[1];
		i++;
		if (env[i])
		{
			next->next = new_list_item();
			next = next->next;
		}
		free(tmp);
	}
	return (head);
}
