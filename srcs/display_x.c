/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 22:30:17 by dhojt             #+#    #+#             */
/*   Updated: 2020/12/03 21:06:16 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_leading_zero(uintmax_t num, char hash, char x)
{
	if (num)
	{
		if (hash == '#' && x == 'x')
			write(1, "0x", 2);
		if (hash == '#' && x == 'X')
			write(1, "0X", 2);
	}
}

static uintmax_t	get_num(t_printf *tab)
{
	uintmax_t	num;

	if (ft_strcmp(tab->length, "hh") == 0)
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

static t_printf		*do_x(t_printf *tab, uintmax_t num, char *str, int align_left)
{
	int			n_b;
	int			n_w;

	if ((n_w = ft_strlen(str)) && tab->flags[4] == '#' && num &&
			tab->flags[3] == '0' && tab->width)
		n_w += 2;
	else if ((n_w = ft_strlen(str)) && tab->flags[4] == '#' && num)
	{
		tab->width -= 2;
		tab->ret += 2;
	}
	n_b = (n_w <= tab->precision && tab->precision > 0) ? tab->precision : n_w;
	tab->ret += (n_b <= tab->width) ? tab->width : n_b;
	if (!align_left)
		put_filling(tab, ' ', tab->width - n_b, 0);
	print_leading_zero(num, tab->flags[4], tab->type);
	put_filling(tab, '0', tab->precision - n_w, 0);
	ft_putstr(str);
	if (align_left)
		put_filling(tab, ' ', tab->width - n_b, 0);
	return (tab);
}

t_printf				*handle_x(t_printf *tab)
{
	char		*str;
	char		c;
	uintmax_t	num;
	int			align_left;

	align_left = 0;
	num = get_num(tab);
	if (num == 0 && tab->precision == 0)
	{
		put_filling(tab, ' ', tab->width, 1);
		return (tab);
	}
	c = 'a';
	if (tab->type == 'X')
		c = 'A';
	if (!(str = ft_itoa_base(num, 16, c)))
		exit(-1);
	if (tab->flags[0] == '-')
		align_left = 1;
	if (tab->flags[3] == '0' && tab->precision == -1 && !tab->flags[0])
		tab->precision = tab->width;
	do_x(tab, num, str, align_left);
	free(str);
	return (tab);
}
