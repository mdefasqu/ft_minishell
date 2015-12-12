/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 13:02:19 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/03/20 13:04:19 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_put_name(char *str, int d)
{
	if (d == 0)
	{
		ft_putstr(str);
		ft_putstr(":\n");
	}
	else if (d == 2)
	{
		ft_putstr(str);
		ft_putstr("/\n");
	}
	else
		ft_putendl(str);
}
