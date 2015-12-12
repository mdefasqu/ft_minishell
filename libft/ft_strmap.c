/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:21:20 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/11/11 00:48:38 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	size_t	i;
	size_t	cmp;

	if (s == NULL || f == NULL)
		return (NULL);
	i = ft_strlen(s);
	cmp = 0;
	dst = (char *)malloc(sizeof(char *) * (i + 1));
	if (dst == NULL)
		return (NULL);
	while (cmp < i)
	{
		dst[cmp] = f((char)s[cmp]);
		cmp++;
	}
	dst[cmp] = '\0';
	return (dst);
}
