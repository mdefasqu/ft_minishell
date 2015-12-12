/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:35:11 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/11/09 22:32:11 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*b;

	b = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (n-- && b)
	{
		if (*b == (unsigned char)c)
			return ((void *)b);
		b++;
	}
	return (NULL);
}
