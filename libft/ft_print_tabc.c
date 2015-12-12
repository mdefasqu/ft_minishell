/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tabc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 11:54:23 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/02 16:34:43 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_tabc(char **tabc)
{
	size_t x;

	x = 0;
	while (tabc[x])
	{
		ft_putstr("line ");
		ft_putnbr(x);
		ft_putstr(" = ");
		ft_putstr(tabc[x]);
		ft_putchar('\n');
		x++;
	}
}
