/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 12:44:02 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/27 11:50:41 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int				ft_len_list(t_list *list)
{
	int	len;

	len = 0;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}

char			*ft_get_post(void)
{
	struct utsname		buf;
	char				*dst;

	uname(&buf);
	dst = ft_strcut(buf.nodename, 0, 6);
	return (dst);
}

void			print_prompt(t_list *list)
{
	char	*tmp;

	tmp = ft_get_post();
	ft_putstr("\033[0;32m->");
	if (find_content_list(list, "USER") == NULL)
		ft_putstr("\033[0;33mAnonymous");
	else
	{
		ft_putstr("\033[0;33m");
		ft_putstr(find_content_list(list, "USER"));
	}
	ft_putstr("\033[0;36m(");
	ft_putstr(tmp);
	ft_putstr(")");
	ft_putstr("\033[0;32m$>\033[0;0m");
	ft_strdel(&tmp);
}

void			handler(unsigned long int sig)
{
	static t_list *env = NULL;

	if (env == NULL)
		env = (t_list *)sig;
	else
	{
		ft_putchar('\n');
		print_prompt(env);
	}
}
