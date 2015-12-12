/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:14:21 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/11/13 11:12:53 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*dst;
	size_t	i;

	if (!size)
		return (NULL);
	i = 0;
	dst = malloc(sizeof(dst) * (size));
	if (!dst)
		return (NULL);
	while (i < size)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}
