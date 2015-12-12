/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 11:48:22 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/06 16:59:30 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int			ft_unsetenv(char **cmd, t_list **list_env)
{
	int		len;
	int		i;

	len = ft_strtab_len(cmd);
	i = 0;
	if (len == 1)
		return (ft_error("unsetenv: Too few arguments.\n", NULL, NULL));
	while (i < len)
	{
		if (is_active(*list_env, cmd[i]) > 0)
		{
			change_active_state(list_env, cmd[i], 0);
			update_old_content_list(list_env, cmd[i],
									find_content_list(*list_env, cmd[i]));
			update_content_list(list_env, cmd[i], NULL);
		}
		i++;
	}
	return (1);
}
