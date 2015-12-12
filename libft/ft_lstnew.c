/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:09:54 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/01/10 16:45:03 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list_libft		*ft_lstnew(void const *content, size_t content_size)
{
	t_list_libft	*list;

	list = (t_list_libft*)malloc(sizeof(*list));
	if (list)
	{
		if (!content)
		{
			list->content = NULL;
			list->content_size = 0;
		}
		else
		{
			list->content = malloc(content_size);
			list->content = ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
		}
		list->next = NULL;
	}
	return (list);
}
