/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tabi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:27:24 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/01/10 15:05:57 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_tabi(int **tabi, int nb_line, int nb_case)
{
	int	x;
	int	y;

	x = 0;
	while (x < nb_line)
	{
		y = 0;
		while (y < nb_case)
		{
			ft_putnbr(tabi[x][y]);
			ft_putchar(' ');
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}
