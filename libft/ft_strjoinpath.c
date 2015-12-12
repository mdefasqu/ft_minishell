/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 12:05:33 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/18 13:13:03 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdlib.h>

char	*ft_strjoin_path(char *s1, char *s2)
{
	ssize_t i;
	ssize_t j;
	char	*finish;

	errno = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	if ((finish = (char *)malloc(sizeof(*finish) * (ft_strlen(s1)
		+ ft_strlen(s2) + 2))) == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		finish[i] = s1[i];
	if (finish[i - 1] != '/')
		finish[i++] = '/';
	j = 0;
	while (s2[j])
		finish[i++] = s2[j++];
	finish[i] = '\0';
	return (finish);
}
