/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 11:57:41 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/06 16:46:29 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void		free_item(t_list *list)
{
	free(list->titre);
	list->titre = NULL;
	free(list->content);
	list->content = NULL;
	free(list);
	list = NULL;
}

void		free_item2(t_list **list)
{
	if ((*list)->titre != NULL)
	{
		free((*list)->titre);
		(*list)->titre = NULL;
	}
	if ((*list)->titre != NULL)
	{
		free((*list)->content);
		(*list)->titre = NULL;
	}
	if (*list != NULL)
	{
		free(*list);
		*list = NULL;
	}
}

void		free_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (list)
	{
		list = list->next;
		free_item(tmp);
		tmp = list;
	}
	return ;
}

void		free_options(t_options **options)
{
	if (*options != NULL)
	{
		free(*options);
		*options = NULL;
	}
}
