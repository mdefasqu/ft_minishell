/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:02:53 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/11/10 14:59:46 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	res;
	int neg;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r' \
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	while (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9')\
				&& res == 0)
			neg = -1;
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		if (str[i + 1] < '0' || str[i + 1] > '9')
			return (res * neg);
		i++;
	}
	return (res * neg);
}
