/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 01:57:01 by dhojt             #+#    #+#             */
/*   Updated: 2020/12/03 20:20:23 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	get_num(t_printf *tab)
{
	uintmax_t	num;

	num = (unsigned long)(va_arg(tab->args, unsigned long int));
	num = (uintmax_t)num;
	return (num);
}

static t_printf		*print_u(t_printf *tab, char *str, int align_left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str) + 2;
	not_blank = num_width;
	tab->len += (not_blank <= tab->field_width) ? tab->field_width : not_blank;
	if (!align_left)
		display_gap(tab, ' ', tab->field_width - not_blank, 0);
	write(1, "0x", 2);
	display_gap(tab, '0', (tab->precision - num_width) + 2, 1);
	ft_putstr(str);
	if (align_left)
		display_gap(tab, ' ', tab->field_width - not_blank, 0);
	free(str);
	return (tab);
}

t_printf				*handle_p(t_printf *tab)
{
	char		*str;
	uintmax_t	num;
	int			align_left;

	align_left = 0;
	num = get_num(tab);
	if (!(str = ft_itoa_base(num, 16, 'a')))
		exit(-1);
	if (tab->convert[0] == '-')
		align_left = 1;
	if (tab->precision == 0 && num == 0)
		*str = '\0';
	if (tab->convert[3] == '0' && tab->precision == -1 && !tab->convert[0])
	{
		tab->precision = tab->field_width - 2;
		tab->field_width = 0;
	}
	print_u(tab, str, align_left);
	return (tab);
}
