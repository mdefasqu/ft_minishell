/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort_char_reverse.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 16:39:31 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/03/24 12:25:33 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bubble_sort_char_reverse(char **tabc, int nb_element)
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
			if (ft_strcmp(tabc[i], tabc[j]) < 0)
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
