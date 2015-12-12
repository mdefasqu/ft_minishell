/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 18:16:33 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/26 18:23:15 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

t_options		*init_option(void)
{
	t_options *options;

	options = (t_options *)malloc(sizeof(t_options));
	options->options_i = 0;
	options->nb_arg_real = 0;
	options->nb_flag = 0;
	options->nb_equal = 0;
	options->nb_command = 0;
	options->error = 0;
	return (options);
}

t_cd_options	*init_cd_option(void)
{
	t_cd_options *options;

	options = (t_cd_options *)malloc(sizeof(t_cd_options));
	options->options_p = 0;
	options->options_l = 0;
	options->nb_arg_real = 0;
	options->nb_flag = 0;
	return (options);
}
