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
#include <stdlib.h>

int			ft_strstr_pos(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return (-1);
	while (s1[i] != '\0')
	{
		if (s2[j] == s1[i])
		{
			while (s2[j] == s1[i])
			{
				j++;
				i++;
				if (s2[j] == '\0')
					return (i - j);
			}
			i = (i - j) + 1;
		}
		else
			i++;
		j = 0;
	}
	return (-1);
}

char		*ft_str_replace_in_str(const char *find, const char *replace,
				const char *str)
{
	char	*ret;
	int		len;
	int		pos;
	int		i;
	int		k;

	if (find == NULL || replace == NULL || str == NULL)
		return (NULL);
	len = strlen(str) + strlen(replace) - strlen(find) + 1;
	ret = (char *)malloc(sizeof(char) * len);
	i = 0;
	k = 0;
	if ((pos = ft_strstr_pos(str, find)) == -1)
		return (NULL);
	while (i < pos)
		ret[k++] = str[i++];
	i = 0;
	while (replace[i] != '\0')
		ret[k++] = replace[i++];
	i = pos + strlen(find);
	while (str[i])
		ret[k++] = str[i++];
	ret[k] = '\0';
	return (ret);
}
