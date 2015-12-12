/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:59:56 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/29 15:53:13 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void			ft_print_bonus(void)
{
	ft_putendl("------------------------------------------------------");
	ft_putendl("|                                                    |");
	ft_putendl("|               Liste des bonus :                    |");
	ft_putendl("|                                                    |");
	ft_putendl("|        - Gestion des droit d'execution dans PATH   |");
	ft_putendl("|        - Prompt avec nom et numero de poste.       |");
	ft_putendl("|        - Builtin cd avec le flag -L et -P.         |");
	ft_putendl("|        - Builtin env avec le flag -i.              |");
	ft_putendl("|        - SHLVL qui s'incremente correctement.      |");
	ft_putendl("|        - Gestion des retour de exit.               |");
	ft_putendl("|        - Gestion des ;.                            |");
	ft_putendl("|        - Gestion des signaux.                      |");
	ft_putendl("|        - Gestion des $env.                         |");
	ft_putendl("|        - Builtin Bonus et star_wars.               |");
	ft_putendl("|                                                    |");
	ft_putendl("------------------------------------------------------");
}

int				ft_bonus_tab(char **cmd)
{
	int i;

	i = ft_strtab_len(cmd);
	if (i > 1)
		ft_putendl("Too many argument");
	else
	{
		ft_putstr("\033[0;33m");
		ft_print_bonus();
		ft_putstr("\033[0;0m");
	}
	return (1);
}
