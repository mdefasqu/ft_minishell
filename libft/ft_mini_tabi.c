/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_tabi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 14:07:39 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/01/30 14:13:23 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_mini_tabi(int *tab, int nb_element)
{
	int i;

	i = 0;
	while (i < nb_element)
	{
		ft_putstr("[");
		ft_putnbr(i);
		ft_putstr("] = ");
		ft_putnbr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}
