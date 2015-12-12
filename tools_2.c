/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 15:18:52 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/30 17:09:49 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char		*get_dollar_macro(const char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (str[i] != '$')
		i++;
	j = i;
	i++;
	while (ft_isalnum(str[i]) == 1)
		i++;
	ret = (char *)malloc(sizeof(char) * (i - j) + 1);
	i = j + 1;
	j = 1;
	ret[0] = '$';
	while (ft_isalnum(str[i]) == 1)
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char		*ft_replace_tild(const char *gnl, t_list *list_env)
{
	char	*ret;

	ret = (char*)gnl;
	if (ft_strchr(gnl, '~') != NULL)
	{
		ret = ft_str_replace_in_str("~",
				find_content_list(list_env, "HOME"), gnl);
	}
	return (ret);
}

int			ft_nb_char_in_str(const char *str, const char c)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			ret++;
		i++;
	}
	return (ret);
}

char		*ft_replace_dollar(const char *gnl, t_list *list_env)
{
	char	*dollar;
	char	*ret;
	int		len;

	len = ft_nb_char_in_str(gnl, '$');
	ret = (char *)gnl;
	while (len > 0)
	{
		dollar = (ret == NULL) ? get_dollar_macro(gnl) : get_dollar_macro(ret);
		if (find_content_list(list_env, dollar + 1) == NULL)
		{
			ret = (ret == NULL) ? ft_str_replace_in_str(dollar, "", gnl)
							: ft_str_replace_in_str(dollar, "", ret);
		}
		else
		{
			ret = (ret == NULL) ? ft_str_replace_in_str(dollar,
						find_content_list(list_env, dollar + 1), gnl)
							: ft_str_replace_in_str(dollar,
						find_content_list(list_env, dollar + 1), ret);
		}
		len--;
	}
	return (ret);
}

char		*ft_replace_orig(const char *gnl, t_list **list_env)
{
	char	*ret;

	ret = NULL;
	if (gnl == NULL)
		return (NULL);
	ret = ft_replace_tild(gnl, *list_env);
	if (ret != NULL)
		ret = ft_replace_dollar(ret, *list_env);
	else
		ret = ft_replace_dollar(gnl, *list_env);
	if (ret == NULL)
		return ((char*)gnl);
	return (ret);
}
