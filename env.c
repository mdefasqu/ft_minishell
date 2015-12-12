/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 11:48:16 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/02 16:30:38 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <stdio.h>

char	**make_env(t_list *list)
{
	char	*line;
	int		i;
	char	**env;
	t_list	*head;

	i = 0;
	head = list;
	env = (char **)malloc(sizeof(char *) * (ft_len_list(list) + 1));
	while (list)
	{
		if (list->is_active == 1)
		{
			line = ft_strjoin(list->titre, "=");
			line = ft_strjoin(line, list->content);
			env[i] = ft_strdup(line);
			i++;
		}
		list = list->next;
	}
	env[i] = ft_strjoin("QAZWSXEDC=", find_old_content_list(head, "PATH"));
	env[i + 1] = ft_strjoin("CDEXSWZAQ=", find_content_list(head, "CDEXSWZAQ"));
	env[i + 2] = NULL;
	return (env);
}

void	print_to_env(t_list *env, char **cmd)
{
	int		i;
	char	**tmp;
	t_list	*add_list;

	i = 1;
	while (cmd[i])
	{
		tmp = ft_strsplit(cmd[i], '=');
		if (find_content_list(env, tmp[0]) == NULL)
		{
			add_list = new_list_item_fill(tmp[0], tmp[1], NULL, 1);
			add_to_list(&env, add_list);
		}
		else
			update_content_list(&env, tmp[0], tmp[1]);
		i++;
	}
	print_to_list(env);
}

char	*get_command_line(char **cmd, t_options *options)
{
	char	*ret;
	int		i;

	ret = NULL;
	i = options->nb_flag + options->nb_equal + 1;
	while (cmd[i])
	{
		ret = ft_strjoin(ret, cmd[i]);
		if (cmd[i + 1])
			ret = ft_strjoin(ret, " ");
		i++;
	}
	return (ret);
}

void	resolve_env(t_list *list, char **cmd,
			t_options *options, t_list *reference)
{
	t_list	*add_list;

	resolve_env_2(&list, options, cmd);
	if (options->nb_command == 0)
		print_to_list(list);
	else
	{
		if (if_titre_exist(list, "PATH") == 0 && options->options_i == 1)
		{
			if (!list)
				list = new_list_item_fill("PATH",
					find_content_list(reference, "PATH"), NULL, 0);
			else
			{
				add_list = new_list_item_fill("PATH",
					find_content_list(reference, "PATH"), NULL, 1);
				add_to_list(&list, add_list);
			}
		}
		parsing(get_command_line(cmd, options), &list);
	}
}

int		ft_env(char **cmd, t_list *list_env)
{
	int			i;
	t_list		*tmp;
	t_options	*options;

	tmp = NULL;
	options = init_option();
	cmd = parse_env(cmd, options, ft_strtab_len(cmd));
	if (options->error == -1)
		return (1);
	if (options->options_i == 0)
		tmp = copy_list(list_env);
	i = ft_strtab_len(cmd);
	if (i == 1)
	{
		print_to_list(list_env);
		free_options(&options);
		free_list(tmp);
		return (1);
	}
	resolve_env(tmp, cmd, options, list_env);
	free_list(tmp);
	free_options(&options);
	return (1);
}
