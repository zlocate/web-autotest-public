/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 02:46:02 by dhojt             #+#    #+#             */
/*   Updated: 2020/12/03 21:06:16 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf			*handle_c(t_printf *tab)
{
	wint_t		c;

	if (ft_strcmp(tab->length, "l") == 0)
		c = (unsigned long)va_arg(tab->args, unsigned long);
	else if (tab->type == 'C')
		c = (wchar_t)va_arg(tab->args, wint_t);
	else
		c = (char)va_arg(tab->args, int);
	c = (wint_t)c;
	if (tab->flags[3] == '0' && tab->flags[0] != '-')
		put_filling(tab, '0', tab->width - 1, 1);
	else if (tab->flags[0] != '-')
		put_filling(tab, ' ', tab->width - 1, 1);
	put_wchar_ret(c, tab);
	if (tab->flags[0] == '-')
		put_filling(tab, ' ', tab->width - 1, 1);
	return (tab);
}
