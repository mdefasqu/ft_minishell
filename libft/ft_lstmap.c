/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:24:04 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/01/10 16:32:37 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list_libft	*ft_lstmap(t_list_libft *lst, t_list_libft *(*f)(t_list_libft*))
{
	t_list_libft	*result;
	t_list_libft	*tmp;
	t_list_libft	*tmp2;

	if (!lst || !f)
		return (NULL);
	tmp2 = f(lst);
	if ((result = ft_lstnew(tmp2->content, tmp2->content_size)))
	{
		tmp = result;
		lst = lst->next;
		while (lst)
		{
			tmp2 = f(lst);
			if (!(tmp->next = ft_lstnew(tmp2->content, tmp2->content_size)))
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (result);
}
