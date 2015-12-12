/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:55:44 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/01/20 11:19:12 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s2[j] == s1[i])
		{
			while (s2[j] == s1[i])
			{
				j++;
				i++;
				if (s2[j] == '\0')
					return ((char *)&s1[i - j]);
			}
			i = (i - j) + 1;
		}
		else
			i++;
		j = 0;
	}
	return ((char *)NULL);
}
