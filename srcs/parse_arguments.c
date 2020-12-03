/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:44:48 by dhojt             #+#    #+#             */
/*   Updated: 2020/12/03 20:56:52 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*parse_lengh(t_printf *tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (LENGTHS[i] != '\0')
	{
		while (LENGTHS[i] == tab->f_treat[tab->i])
		{
			tab->length[j] = tab->f_treat[tab->i];
			tab->length[j + 1] = '\0';
			tab->i++;
			j++;
		}
		i++;
	}
	return (tab);
}
