/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:01:33 by dhojt             #+#    #+#             */
/*   Updated: 2020/12/03 21:06:16 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf	*display_percent(t_printf *tab)
{
	if (tab->flags[3] == '0' && tab->precision <= 0 && !tab->flags[0])
	{
		tab->precision = tab->width;
		tab->width = 0;
	}
	if (tab->flags[0] != '-')
		put_filling(tab, ' ', tab->width - 1, 1);
	if (tab->flags[3] == '0')
		put_filling(tab, '0', tab->precision - 1, 1);
	write(1, "%", 1);
	if (tab->flags[0] == '-')
		put_filling(tab, ' ', tab->width - 1, 1);
	tab->ret++;
	return (tab);
}

t_printf			*handle_other(t_printf *tab)
{
	if (tab->f_treat[tab->i] == '%')
	{
		display_percent(tab);
		return (tab);
	}
	if (tab->flags[3] == '0' && tab->precision <= 0 && !tab->flags[0])
	{
		tab->precision = tab->width;
		tab->width = 0;
	}
	if (tab->flags[0] != '-')
		put_filling(tab, ' ', tab->width - 1, 1);
	if (tab->flags[3] == '0')
		put_filling(tab, '0', tab->precision - 1, 1);
	write(1, &tab->f_copy[tab->i], 1);
	if (tab->flags[0] == '-')
		put_filling(tab, ' ', tab->width - 1, 1);
	tab->ret++;
	return (tab);
}
