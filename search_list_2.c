/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_list_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 14:30:20 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/27 14:30:21 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		if_titre_exist(t_list *list, const char *titre)
{
	while (list)
	{
		if (ft_strcmp(list->titre, titre) == 0)
			return (1);
		list = list->next;
	}
	return (0);
}

void	update_content_list(t_list **list, const char *titre,
							const char *content)
{
	t_list *head;

	head = *list;
	while (head)
	{
		if (ft_strcmp(head->titre, titre) == 0)
			head->content = ft_strdup(content);
		head = head->next;
	}
}

void	update_old_content_list(t_list **list, const char *titre,
								const char *content)
{
	t_list *head;

	head = *list;
	while (head)
	{
		if (ft_strcmp(head->titre, titre) == 0)
			head->old_content = ft_strdup(content);
		head = head->next;
	}
}
