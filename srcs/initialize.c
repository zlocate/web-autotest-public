/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:43:08 by dhojt             #+#    #+#             */
/*   Updated: 2020/12/03 21:08:04 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*init(t_printf *tab)
{
	tab->ret = 0;
	tab->i = 0;
	tab->f_treat = (char *)tab->raw_string;
	tab->f_copy = (char *)tab->raw_string;
	return (tab);
}

t_printf	*reinit(t_printf *tab)
{
	tab->type = '\0';
	tab->flags[0] = '\0';
	tab->flags[1] = '\0';
	tab->flags[2] = '\0';
	tab->flags[3] = '\0';
	tab->flags[4] = '\0';
	tab->flags[5] = '\0';
	tab->length[0] = '\0';
	tab->length[1] = '\0';
	tab->precision = -1;
	tab->width = 0;
	return (tab);
}
