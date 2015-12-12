/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:12:41 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/11/08 19:00:11 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	cmp;

	cmp = 0;
	if (s && f)
	{
		i = ft_strlen(s);
		while (cmp < i)
		{
			(*f)(cmp, s);
			cmp++;
			s++;
		}
	}
}
