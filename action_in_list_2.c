/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_in_list_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 14:14:28 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/27 14:14:29 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

t_list		*ft_make_list(char *tab)
{
	int		i;
	t_list	*head;
	t_list	*list;
	char	**step;

	i = 0;
	if (ft_strcmp(tab, "/") == 0)
		return (new_list_item_fill("/", NULL, NULL, 1));
	if ((step = ft_strsplit(tab, '/')) == NULL)
		ft_error("erreur dans ft_make_list.c", NULL, NULL);
	list = new_list_item();
	head = list;
	while (step[i])
	{
		list->titre = ft_strdup(step[i]);
		if (step[i + 1])
		{
			list->next = new_list_item();
			list = list->next;
		}
		i++;
	}
	return (head);
}

void		remove_last(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	free_item2(&tmp->next);
	tmp->next = NULL;
}

t_list		*copy_list(t_list *source)
{
	t_list	*tmp;
	t_list	*head;
	t_list	*new_list;

	new_list = new_list_item();
	head = new_list;
	tmp = source;
	while (tmp)
	{
		new_list->titre = ft_strdup(tmp->titre);
		new_list->content = ft_strdup(tmp->content);
		new_list->old_content = ft_strdup(tmp->old_content);
		if (tmp->next != NULL)
		{
			new_list->next = new_list_item();
			new_list = new_list->next;
		}
		tmp = tmp->next;
	}
	return (head);
}

t_list		*new_list_item(void)
{
	t_list	*item;

	item = (t_list *)malloc(sizeof(t_list));
	item->titre = NULL;
	item->content = NULL;
	item->old_content = NULL;
	item->next = NULL;
	item->is_active = 1;
	return (item);
}
