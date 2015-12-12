/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 23:07:08 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/11/11 00:47:58 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*dst;
	int		i;
	int		d;

	i = 0;
	d = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	dst = (char *)malloc(sizeof(char *) * (ft_strlen(s) + 1));
	if (dst == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dst[d] = s[i];
		d++;
		i++;
	}
	dst[d] = '\0';
	d--;
	while (dst[d] == ' ' || dst[d] == '\n' || dst[d] == '\t')
		d--;
	dst[d + 1] = '\0';
	return (dst);
}
