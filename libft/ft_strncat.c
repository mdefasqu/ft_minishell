/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:06:27 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/11/07 00:57:04 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	a;
	size_t	b;

	b = ft_strlen(s1);
	a = 0;
	while (s2[a] != '\0')
	{
		if (a == n)
			s1[b] = '\0';
		else
			s1[b] = s2[a];
		b++;
		a++;
	}
	s1[b] = s2[a];
	return (s1);
}
