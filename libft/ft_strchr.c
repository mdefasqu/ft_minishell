/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:17:46 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/11/09 18:09:04 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strchr(const char *s, int c)
{
	char	b;
	size_t	i;
	size_t	a;

	i = 0;
	b = (char)c;
	a = ft_strlen(s);
	while (i <= a)
	{
		if (s[i] == (char)b)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
