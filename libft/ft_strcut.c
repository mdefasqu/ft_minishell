/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 11:57:50 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/02 11:57:51 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strcut(const char *str, int start, int end)
{
	char	*ret;
	int		i;

	i = 0;
	if (start < 0 || (end - start) < 0)
		return (NULL);
	if (end > (int)ft_strlen(str))
		end = ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * (end - start) + 1);
	while (start <= end)
	{
		ret[i] = str[start];
		start++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
