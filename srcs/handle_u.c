/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:06:18 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:06:19 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	get_num(t_printf *tab)
{
	uintmax_t	num;

	if (tab->type == 'U')
		num = (unsigned long)(va_arg(tab->args, unsigned long int));
	else if (ft_strcmp(tab->length, "hh") == 0)
		num = (unsigned char)(va_arg(tab->args, unsigned int));
	else if (ft_strcmp(tab->length, "h") == 0)
		num = (unsigned short)(va_arg(tab->args, unsigned int));
	else if (ft_strcmp(tab->length, "ll") == 0)
		num = (unsigned long long)(va_arg(tab->args, unsigned long long int));
	else if (ft_strcmp(tab->length, "l") == 0)
		num = (unsigned long)(va_arg(tab->args, unsigned long int));
	else if (ft_strcmp(tab->length, "j") == 0)
		num = (uintmax_t)(va_arg(tab->args, uintmax_t));
	else if (ft_strcmp(tab->length, "z") == 0)
		num = (size_t)(va_arg(tab->args, size_t));
	else
		num = (unsigned int)(va_arg(tab->args, unsigned int));
	num = (uintmax_t)num;
	return (num);
}

static int			get_tens(uintmax_t num)
{
	int tens;

	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static t_printf		*do_u(t_printf *tab, uintmax_t num, int num_width, int left)
{
	int			not_blank;

	not_blank = num_width;
	if (num_width <= tab->precision)
		not_blank = tab->precision;
	tab->ret += (not_blank <= tab->width) ? tab->width : not_blank;
	if (!left)
		put_filling(tab, ' ', tab->width - not_blank, 0);
	put_filling(tab, '0', tab->precision - num_width, 0);
	ft_putnbrmax_u(num);
	if (left)
		put_filling(tab, ' ', tab->width - not_blank, 0);
	return (tab);
}

t_printf				*handle_u(t_printf *tab)
{
	uintmax_t	num;
	int			num_width;
	int			left;

	left = 0;
	num = get_num(tab);
	if (num == 0 && tab->precision == 0)
	{
		put_filling(tab, ' ', tab->width, 1);
		return (tab);
	}
	num_width = get_tens(num);
	if (tab->flags[0] == '-')
		left = 1;
	if (tab->flags[3] == '0' && tab->precision == -1 && !tab->flags[0])
		tab->precision = tab->width;
	do_u(tab, num, num_width, left);
	return (tab);
}
