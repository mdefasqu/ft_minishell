/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:45:18 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/11/14 14:09:17 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*mp;

	mp = (char *)malloc(sizeof(mp) * len);
	if (mp == NULL)
		return (NULL);
	mp = ft_memcpy(mp, src, len);
	dst = ft_memcpy(dst, mp, len);
	free(mp);
	return (dst);
}
