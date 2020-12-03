/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:06:18 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:17:32 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	get_num(t_printf *props)
{
	uintmax_t	num;

	if (props->type == 'U')
		num = (unsigned long)(va_arg(props->args, unsigned long int));
	else if (ft_strcmp(props->length, "hh") == 0)
		num = (unsigned char)(va_arg(props->args, unsigned int));
	else if (ft_strcmp(props->length, "h") == 0)
		num = (unsigned short)(va_arg(props->args, unsigned int));
	else if (ft_strcmp(props->length, "ll") == 0)
		num = (unsigned long long)(va_arg(props->args, unsigned long long int));
	else if (ft_strcmp(props->length, "l") == 0)
		num = (unsigned long)(va_arg(props->args, unsigned long int));
	else if (ft_strcmp(props->length, "j") == 0)
		num = (uintmax_t)(va_arg(props->args, uintmax_t));
	else if (ft_strcmp(props->length, "z") == 0)
		num = (size_t)(va_arg(props->args, size_t));
	else
		num = (unsigned int)(va_arg(props->args, unsigned int));
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

static t_printf		*do_u(t_printf *props, uintmax_t num, int n_width, int left)
{
	int			not_blank;

	not_blank = n_width;
	if (n_width <= props->precision)
		not_blank = props->precision;
	props->ret += (not_blank <= props->width) ? props->width : not_blank;
	if (!left)
		put_filling(props, ' ', props->width - not_blank, 0);
	put_filling(props, '0', props->precision - n_width, 0);
	ft_putnbrmax_u(num);
	if (left)
		put_filling(props, ' ', props->width - not_blank, 0);
	return (props);
}

t_printf			*handle_u(t_printf *props)
{
	uintmax_t	num;
	int			n_width;
	int			left;

	left = 0;
	num = get_num(props);
	if (num == 0 && props->precision == 0)
	{
		put_filling(props, ' ', props->width, 1);
		return (props);
	}
	n_width = get_tens(num);
	if (props->flags[0] == '-')
		left = 1;
	if (props->flags[3] == '0' && props->precision == -1 && !props->flags[0])
		props->precision = props->width;
	do_u(props, num, n_width, left);
	return (props);
}
