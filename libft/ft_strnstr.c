/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:00:54 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/01/14 12:57:12 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		s2_len;
	size_t		count;
	char		*str1;

	if (s1 && s1)
	{
		s2_len = ft_strlen(s2);
		str1 = (char *)s1;
		if (ft_strlen(str1) < s2_len)
			return (NULL);
		if (!s2_len)
			return (str1);
		if (s2_len > n)
			return (NULL);
		count = n - s2_len + 1;
		while (count)
		{
			if (!ft_memcmp(str1, s2, s2_len))
				return (str1);
			str1++;
			count--;
		}
	}
	return (NULL);
}
