/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:27:45 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/03/16 17:53:21 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int a;
	int b;

	b = ft_strlen(s1);
	a = 0;
	while (s2[a] != '\0')
	{
		s1[b] = s2[a];
		b++;
		a++;
	}
	s1[b] = '\0';
	return (s1);
}
