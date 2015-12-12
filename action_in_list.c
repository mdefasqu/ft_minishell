/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_in_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 17:16:43 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/06 16:40:35 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

t_list		*new_list_item_fill(const char *titre, const char *content,
				const char *old_content, int is_active)
{
	t_list	*item;

	item = (t_list *)malloc(sizeof(t_list));
	item->titre = ft_strdup(titre);
	item->content = ft_strdup(content);
	item->is_active = is_active;
	item->next = NULL;
	item->old_content = ft_strdup(old_content);
	return (item);
}

void		add_to_list(t_list **list, t_list *to_add)
{
	t_list *begin;

	if (!list || !to_add)
		return ;
	begin = *list;
	while (begin->next)
		begin = begin->next;
	begin->next = to_add;
}

void		del_to_list_two(t_list **begin, t_list **next)
{
	(*begin)->next = (*next)->next;
	free_item(*next);
	*next = (*begin)->next;
}

void		del_to_list(t_list **list, const char *titre)
{
	t_list *begin;
	t_list *next;

	if (!list)
		return ;
	begin = *list;
	next = begin->next;
	if (ft_strcmp(begin->titre, titre) == 0)
	{
		if (begin->next != NULL)
			*list = begin->next;
		free_item(begin);
		return ;
	}
	while (next)
	{
		if (ft_strcmp(next->titre, titre) == 0)
			del_to_list_two(&begin, &next);
		else
		{
			next = next->next;
			begin = begin->next;
		}
	}
}

int			print_to_list(t_list *list)
{
	while (list)
	{
		if (list->is_active == 1)
		{
			ft_putstr(list->titre);
			ft_putchar('=');
			if (list->content != NULL)
				ft_putstr(list->content);
			ft_putchar('\n');
		}
		list = list->next;
	}
	return (1);
}
