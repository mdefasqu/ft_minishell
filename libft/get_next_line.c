/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 12:40:31 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/12/09 12:42:20 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static int			ft_solve(t_box *box, char **line, int fd)
{
	int				i;

	i = 0;
	if (!(*line = (char *)malloc(sizeof(line))))
		return (-1);
	if (box->fd != fd)
		box->fd = fd;
	while (box->tmp[i])
	{
		if (box->tmp[i] == '\n')
		{
			*line = ft_strsub(box->tmp, 0, i);
			i++;
			box->tmp = ft_strcpy(box->tmp, &(box->tmp[i]));
			return (1);
		}
		i++;
	}
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_box	box;

	if (fd < 0 || fd >= 99 || (fd == 1 && line == NULL) || BUFF_SIZE <= 0
			|| line == NULL)
		return (-1);
	if (box.tmp == NULL)
		box.fd = fd;
	if (!box.tmp || box.fd != fd)
		if (!(box.tmp = (char *)malloc(sizeof(*box.tmp))))
			return (-1);
	while ((box.ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[box.ret] = '\0';
		box.tmp = ft_strjoin(box.tmp, buf);
		if (ft_solve(&box, line, fd) == 1)
			return (1);
	}
	if (box.ret < 0)
		return (-1);
	if (ft_solve(&box, line, fd) == 1)
		return (1);
	*line = ft_strcpy(box.tmp, box.tmp);
	return (0);
}
