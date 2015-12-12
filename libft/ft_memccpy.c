/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:30:22 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/11/10 12:41:54 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tion;
	unsigned char	*rce;
	unsigned char	p;

	if (!n)
		return (NULL);
	tion = (unsigned char *)dst;
	p = (size_t)c;
	rce = (unsigned char *)src;
	while (n > 0)
	{
		if ((*tion++ = *rce++) == p)
			return (tion);
		n--;
	}
	return (NULL);
}
