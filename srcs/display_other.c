/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:01:33 by dhojt             #+#    #+#             */
/*   Updated: 2020/12/03 20:20:50 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf	*display_percent(t_printf *tab)
{
	if (tab->convert[3] == '0' && tab->precision <= 0 && !tab->convert[0])
	{
		tab->precision = tab->field_width;
		tab->field_width = 0;
	}
	if (tab->convert[0] != '-')
		display_gap(tab, ' ', tab->field_width - 1, 1);
	if (tab->convert[3] == '0')
		display_gap(tab, '0', tab->precision - 1, 1);
	write(1, "%", 1);
	if (tab->convert[0] == '-')
		display_gap(tab, ' ', tab->field_width - 1, 1);
	tab->len++;
	return (tab);
}

t_printf			*handle_other(t_printf *tab)
{
	if (tab->f_treat[tab->i] == '%')
	{
		display_percent(tab);
		return (tab);
	}
	if (tab->convert[3] == '0' && tab->precision <= 0 && !tab->convert[0])
	{
		tab->precision = tab->field_width;
		tab->field_width = 0;
	}
	if (tab->convert[0] != '-')
		display_gap(tab, ' ', tab->field_width - 1, 1);
	if (tab->convert[3] == '0')
		display_gap(tab, '0', tab->precision - 1, 1);
	write(1, &tab->f_copy[tab->i], 1);
	if (tab->convert[0] == '-')
		display_gap(tab, ' ', tab->field_width - 1, 1);
	tab->len++;
	return (tab);
}
