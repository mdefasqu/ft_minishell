/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:10:10 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/11/08 10:59:25 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*o;

	i = 0;
	o = (unsigned char *)s;
	if (n == 0)
		return ;
	else
	{
		while (n > i)
		{
			o[i] = '\0';
			i++;
		}
	}
}
