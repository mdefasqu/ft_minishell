/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_with_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 14:21:19 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/29 17:41:06 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int				inc_norme(size_t *len, const char **s)
{
	(*len)++;
	(*s)++;
	while (**s != '"')
	{
		(*len)++;
		(*s)++;
	}
	return (1);
}

static int		ft_copy_str(const char *s, char c, size_t size_array,
							char **ret)
{
	size_t		i;
	size_t		len_str;

	i = 0;
	len_str = 0;
	while (i < size_array)
	{
		if (*s == '"')
			inc_norme(&len_str, &s);
		if (*s != c && *s != '\0')
			len_str++;
		else if (len_str)
		{
			if ((ret[i] = (char *)malloc(sizeof(**ret) * len_str + 1)) == NULL)
				return (1);
			ft_strncpy(ret[i], s - len_str, len_str);
			ret[i++][len_str] = '\0';
			len_str = 0;
		}
		s++;
	}
	return (0);
}

static size_t	ft_get_size_array(const char *s, char c)
{
	size_t		size_array;
	char const	*temp_s;
	int			same;

	same = 0;
	size_array = 0;
	temp_s = s;
	while (*temp_s != '\0')
	{
		if (*temp_s == '"')
		{
			if (*(temp_s - 1) != ' ')
				same = 1;
			temp_s++;
			while (*temp_s != '"')
				temp_s++;
			if (*(temp_s + 1) != '"' && same == 0)
				size_array++;
		}
		if (*temp_s != c && (*(temp_s - 1) == c || (temp_s - 1) < s))
			size_array++;
		temp_s++;
	}
	return (size_array);
}

char			**ft_split_with_quote(const char *s, char c)
{
	char		**ret;
	size_t		size_array;

	if (s == NULL)
		return (NULL);
	size_array = ft_get_size_array(s, c);
	ret = (char **)malloc(sizeof(*ret) * (size_array + 1));
	if (ret == NULL)
		return (NULL);
	if (ft_copy_str(s, c, size_array, ret))
		return (NULL);
	ret[size_array] = NULL;
	return (ret);
}
