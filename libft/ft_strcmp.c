/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 09:49:30 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/30 12:41:34 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2++)
	{
		if (*s1++ == 0)
			return (0);
	}
	return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
