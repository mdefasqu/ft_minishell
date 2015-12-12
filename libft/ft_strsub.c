/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:53:13 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/11/14 15:26:42 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	int		a;

	if (!s || start > ft_strlen(s) || len > ft_strlen(s) - start)
		return (NULL);
	i = 0;
	a = start;
	dst = (char *)malloc(sizeof(char *) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = s[a];
		i++;
		a++;
	}
	dst[i] = '\0';
	return (dst);
}
