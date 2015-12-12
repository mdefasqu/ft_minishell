/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:40:40 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/11/10 12:55:41 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	cmp;
	char	*dst;

	if (s == NULL || f == NULL)
		return (NULL);
	i = ft_strlen(s);
	cmp = 0;
	dst = (char *)malloc(sizeof(char *) * (i + 1));
	if (dst == NULL)
		return (NULL);
	while (cmp < i)
	{
		dst[cmp] = f(cmp, (char)s[cmp]);
		cmp++;
	}
	dst[cmp] = '\0';
	return (dst);
}
