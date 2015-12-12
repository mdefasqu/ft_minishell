/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 17:09:21 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/30 15:30:36 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char			**del_one_argv(char **argv, int i)
{
	char		**finish;
	int			y;

	y = 0;
	while (argv[y])
		y++;
	finish = (char **)malloc(sizeof(char *) * (y));
	y = 0;
	while (y < i)
	{
		finish[y] = ft_strdup(argv[y]);
		y++;
	}
	i++;
	while (argv[i])
	{
		finish[y] = ft_strdup(argv[i]);
		y++;
		i++;
	}
	finish[y] = NULL;
	return (finish);
}

int				ft_nb_guillemet(char *str)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] == '"')
			y++;
		i++;
	}
	return (y);
}

char			*ft_strdup_guillemet(char *str)
{
	char	*dst;
	int		i;
	int		y;

	i = 0;
	y = 0;
	y = ft_strlen(str);
	i = ft_nb_guillemet(str);
	dst = (char *)malloc(sizeof(char) * (y - i + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] != '"')
		{
			dst[y] = str[i];
			y++;
		}
		i++;
	}
	dst[y] = '\0';
	return (dst);
}

void			ft_remove_guillemet(char **str)
{
	int i;
	int	y;

	y = 0;
	i = 0;
	while (str[i])
	{
		y = 0;
		while (str[i][y])
		{
			if (str[i][y] == '"')
			{
				str[i] = ft_strdup_guillemet(str[i]);
				break ;
			}
			y++;
		}
		i++;
	}
}

void			init_env(char **env)
{
	char		*pwd;

	pwd = get_pwd();
	pwd = ft_strjoin("PWD=", pwd);
	*env = pwd;
	*(env + 1) = NULL;
}
