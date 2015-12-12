/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 15:41:53 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/29 18:14:33 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int			removetab(char *source)
{
	int i;
	int z;

	i = 0;
	z = 0;
	while (source[i])
	{
		if (source[i] == '"')
		{
			if (z == 0)
				z = 1;
			else
				z = 0;
		}
		if (source[i] == '\t' && z == 0)
			source[i] = ' ';
		i++;
	}
	if (z == 1)
	{
		ft_error("Unmatched \".\n", NULL, NULL);
		return (-1);
	}
	return (1);
}

int			check_double(const char *source)
{
	int i;

	i = 0;
	if (source == NULL)
		return (-1);
	while (source[i])
	{
		if (source[i] == ';' && source[i + 1] == ';')
		{
			return (ft_error("ft_minishell1: parse error near `;;'\n",
					NULL, NULL));
		}
		i++;
	}
	return (1);
}

int			ft_clean_param_two(char **upper_2d, int z, int i,
				char ****final_tab)
{
	char	**lower_2d;
	int		y;

	if (removetab(upper_2d[i]) == -1)
		return (-1);
	if (upper_2d[i][0] == '\0')
		return (0);
	lower_2d = ft_split_with_quote(upper_2d[i], ' ');
	ft_remove_guillemet(lower_2d);
	if (lower_2d == NULL)
		return (-1);
	y = 0;
	while (lower_2d[y])
		y++;
	(*final_tab)[z] = (char **)malloc(sizeof(char *) * y + 1);
	y = 0;
	while (lower_2d[y])
	{
		(*final_tab)[z][y] = ft_strdup(lower_2d[y]);
		y++;
	}
	(*final_tab)[z][y] = NULL;
	ft_strdel_2d(&lower_2d);
	return (1);
}

char		***ft_clean_param(const char *source)
{
	char	***final_tab;
	char	**upper_2d;
	int		i;
	int		z;

	i = 0;
	z = 0;
	if ((source = ft_strtrim(source)) == NULL)
		return (NULL);
	if (check_double(source) == -1)
		return (NULL);
	if ((upper_2d = ft_strsplit(source, ';')) == NULL)
		return (NULL);
	final_tab = (char ***)malloc(sizeof(char **) * ft_strtab_len(upper_2d) + 1);
	while (upper_2d[i])
	{
		if (ft_clean_param_two(upper_2d, z, i, &final_tab) == 1)
			z++;
		else
			return (NULL);
		i++;
	}
	final_tab[z] = NULL;
	ft_strdel_2d(&upper_2d);
	return (final_tab);
}
