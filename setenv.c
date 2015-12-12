/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 11:48:28 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/29 14:12:06 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void		update_env_content(t_list **list_env, const char *cmd,
								const char *val)
{
	update_old_content_list(list_env, cmd, find_content_list(*list_env, cmd));
	update_content_list(list_env, cmd, val);
	change_active_state(list_env, cmd, 1);
}

int			check_equal(char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (ft_strchr(cmd[i], '=') != NULL)
		{
			return (-1);
		}
		i++;
	}
	return (1);
}

int			ft_setenv(char **cmd, t_list **list_env)
{
	int		len;
	char	*val;

	len = ft_strtab_len(cmd);
	if (check_equal(cmd) < 0)
		return (ft_error(NULL, NULL, "setenv: Syntax Error.\n"));
	if (len == 1)
		return (print_to_list(*list_env));
	else if (len == 2 || len == 3)
	{
		if (len == 2)
			val = NULL;
		else
			val = cmd[2];
		if (check_title(*list_env, cmd[1]) == 1)
			update_env_content(list_env, cmd[1], val);
		else
			add_to_list(list_env, new_list_item_fill(cmd[1], val, NULL, 1));
		return (1);
	}
	else
		ft_error("setenv: Too many arguments.\n", NULL, NULL);
	return (-1);
}
