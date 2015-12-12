/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 11:57:54 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/06 16:52:49 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	change_active_state(t_list **list, const char *titre, int value)
{
	t_list *head;

	head = *list;
	while (head)
	{
		if (ft_strcmp(head->titre, titre) == 0)
			head->is_active = value;
		head = head->next;
	}
}

int		check_title(t_list *list, const char *title)
{
	while (list)
	{
		if (ft_strcmp(title, list->titre) == 0)
			return (1);
		list = list->next;
	}
	return (0);
}

char	*find_content_list(t_list *list, const char *titre)
{
	while (list)
	{
		if (ft_strcmp(list->titre, titre) == 0)
			return (list->content);
		list = list->next;
	}
	return (NULL);
}

char	*find_old_content_list(t_list *list, const char *titre)
{
	while (list)
	{
		if (ft_strcmp(list->titre, titre) == 0)
			return (list->old_content);
		list = list->next;
	}
	return (NULL);
}

int		is_active(t_list *list, const char *titre)
{
	while (list)
	{
		if (ft_strcmp(list->titre, titre) == 0)
			return (list->is_active);
		list = list->next;
	}
	return (-1);
}
