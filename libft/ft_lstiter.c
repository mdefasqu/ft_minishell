/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:21:26 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/01/10 16:32:03 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstiter(t_list_libft *lst, void (*f)(t_list_libft *elem))
{
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
