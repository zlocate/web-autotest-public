/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:45:37 by dhojt             #+#    #+#             */
/*   Updated: 2020/12/02 15:19:15 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*parse_specifier(t_tab *tab)
{
	size_t	i;

	i = 0;
	while (SPECIFIERS[i] != '\0')
	{
		if (SPECIFIERS[i] == tab->f_treat[tab->i])
			tab->specifier_flag = SPECIFIERS[i];
		i++;
	}
	return (tab);
}
