/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:14:28 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/11/10 11:34:38 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (size));
	if (!dst)
		return (NULL);
	while (i <= size)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
