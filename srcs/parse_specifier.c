/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:45:37 by dhojt             #+#    #+#             */
/*   Updated: 2020/12/03 20:21:41 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*parse_specifier(t_printf *tab)
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
