/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:07:19 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/11/08 20:23:28 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	i;
	size_t	cmp;

	cmp = 0;
	if (s && f)
	{
		i = ft_strlen(s);
		while (cmp < i)
		{
			(*f)(s);
			cmp++;
			s++;
		}
	}
}
