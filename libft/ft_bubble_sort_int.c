/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 11:42:01 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/01/27 10:58:43 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bubble_sort_int(int *tabi, int nb_element)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	if (!tabi || nb_element <= 0)
		return ;
	while (i < nb_element - 1)
	{
		j = i + 1;
		while (j < nb_element)
		{
			if (tabi[i] > tabi[j])
			{
				tmp = tabi[i];
				tabi[i] = tabi[j];
				tabi[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
