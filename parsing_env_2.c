/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 11:28:07 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/28 11:28:14 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int			check_flag_all(char c, t_options *options)
{
	if (c == 'i')
	{
		options->options_i = 1;
		return (1);
	}
	else
	{
		ft_error_parse_env(c);
		options->error = -1;
		return (-1);
	}
}
