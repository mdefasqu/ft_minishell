/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 13:35:41 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/27 13:35:43 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	resolve_env_2(t_list **list, t_options *options, char **cmd)
{
	int		i;
	int		y;
	char	**line;
	t_list	*add_list;

	y = options->nb_flag + 1 + options->nb_equal;
	i = options->nb_flag + 1;
	while (i < y)
	{
		line = ft_strsplit(cmd[i], '=');
		if (find_content_list(*list, line[0]) == NULL)
		{
			if (!*list)
				*list = new_list_item_fill(line[0], line[1], NULL, 1);
			else
			{
				add_list = new_list_item_fill(line[0], line[1], NULL, 1);
				add_to_list(list, add_list);
			}
		}
		else
			update_content_list(list, line[0], line[1]);
		i++;
	}
}
