/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 18:30:09 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/30 15:29:53 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		main(int argc, char **argv, char **env)
{
	char	*command;
	t_list	*list_env;

	if (*env == NULL)
		init_env(env);
	list_env = get_env(env);
	set_balise(&list_env);
	signal(3, (void(*)())handler);
	signal(18, (void(*)())handler);
	signal(SIGINT, (void(*)())handler);
	handler((unsigned long int)list_env);
	while (42)
	{
		print_prompt(list_env);
		if (get_next_line(0, &command) == 0)
		{
			ft_putstr(" exit\n");
			break ;
		}
		parsing(command, &list_env);
		ft_strdel(&command);
	}
	return (0);
	(void)argv;
	(void)argc;
}
