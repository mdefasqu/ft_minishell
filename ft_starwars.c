/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starwars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 14:17:09 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/27 14:17:11 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int			ft_star_wars(char **cmd, t_list **list_env)
{
	int		len;

	len = ft_strtab_len(cmd);
	if (len != 1)
		return (ft_error("You can't join the force !\n", NULL, NULL));
	parsing("telnet towel.blinkenlights.nl", list_env);
	return (1);
}
