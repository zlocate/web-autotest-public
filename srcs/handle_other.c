/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:05:49 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:05:50 by rczarfun         ###   ########.fr       */
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
	if (tab->raw_string[tab->i] == '%')
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
	write(1, &tab->raw_string[tab->i], 1);
	if (tab->flags[0] == '-')
		put_filling(tab, ' ', tab->width - 1, 1);
	tab->ret++;
	return (tab);
}
