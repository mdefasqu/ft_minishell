/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tabc_debug.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:15:36 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/01/21 15:48:30 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_tabc_debug(char **tabc)
{
	int x;
	int y;

	x = 0;
	while (tabc[x])
	{
		y = 0;
		while (tabc[x][y] != '\0')
		{
			ft_putstr("tabc[");
			ft_putnbr(x);
			ft_putstr("][");
			ft_putnbr(y);
			ft_putstr("] =");
			ft_putchar(tabc[x][y]);
			ft_putchar('\n');
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}
