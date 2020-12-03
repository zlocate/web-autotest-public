/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:06:00 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:14:43 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	get_num(t_printf *props)
{
	uintmax_t	num;

	num = (unsigned long)(va_arg(props->args, unsigned long int));
	num = (uintmax_t)num;
	return (num);
}

static t_printf		*print_u(t_printf *props, char *str, int align_left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str) + 2;
	not_blank = num_width;
	props->ret += (not_blank <= props->width) ? props->width : not_blank;
	if (!align_left)
		put_filling(props, ' ', props->width - not_blank, 0);
	write(1, "0x", 2);
	put_filling(props, '0', (props->precision - num_width) + 2, 1);
	ft_putstr(str);
	if (align_left)
		put_filling(props, ' ', props->width - not_blank, 0);
	free(str);
	return (props);
}

t_printf			*handle_p(t_printf *props)
{
	char		*str;
	uintmax_t	num;
	int			align_left;

	align_left = 0;
	num = get_num(props);
	if (!(str = ft_itoa_base(num, 16, 'a')))
		exit(-1);
	if (props->flags[0] == '-')
		align_left = 1;
	if (props->precision == 0 && num == 0)
		*str = '\0';
	if (props->flags[3] == '0' && props->precision == -1 && !props->flags[0])
	{
		props->precision = props->width - 2;
		props->width = 0;
	}
	print_u(props, str, align_left);
	return (props);
}
