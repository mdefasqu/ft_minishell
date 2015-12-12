/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 11:24:38 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/01/26 16:44:41 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bubble_sort_char(char **tabc, int nb_element)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (!tabc || nb_element <= 0)
		return ;
	while (i < nb_element - 1)
	{
		j = i + 1;
		while (j < nb_element)
		{
			if (ft_strcmp(tabc[i], tabc[j]) > 0)
			{
				tmp = tabc[i];
				tabc[i] = tabc[j];
				tabc[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
