/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:44:59 by dhojt             #+#    #+#             */
/*   Updated: 2020/12/03 20:58:31 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*parse_flags(t_printf *tab)
{
	size_t	i;

	i = 0;
	while (FLAGS[i] != '\0')
	{
		while (FLAGS[i] == tab->f_treat[tab->i])
		{
			while (tab->f_treat[tab->i] == '-' && tab->i++)
				tab->flags[0] = '-';
			while (tab->f_treat[tab->i] == '+' && tab->i++)
				tab->flags[1] = '+';
			while (tab->f_treat[tab->i] == ' ' && tab->i++)
				tab->flags[2] = ' ';
			while (tab->f_treat[tab->i] == '0' && tab->i++)
				tab->flags[3] = '0';
			while (tab->f_treat[tab->i] == '#' && tab->i++)
				tab->flags[4] = '#';
			i = 0;
		}
		i++;
	}
	return (tab);
}
