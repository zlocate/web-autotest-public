/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:05:19 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:23:05 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	get_num(t_printf *props)
{
	intmax_t	n;

	if (props->type == 'D')
		n = (long)(va_arg(props->args, long int));
	else if (ft_strcmp(props->length, "hh") == 0)
		n = (signed char)(va_arg(props->args, int));
	else if (ft_strcmp(props->length, "h") == 0)
		n = (short)(va_arg(props->args, int));
	else if (ft_strcmp(props->length, "ll") == 0)
		n = (long long)(va_arg(props->args, long long int));
	else if (ft_strcmp(props->length, "l") == 0)
		n = (long)(va_arg(props->args, long int));
	else if (ft_strcmp(props->length, "j") == 0)
		n = (intmax_t)(va_arg(props->args, intmax_t));
	else if (ft_strcmp(props->length, "z") == 0)
		n = (size_t)(va_arg(props->args, size_t));
	else
		n = (int)(va_arg(props->args, int));
	n = (intmax_t)n;
	return (n);
}

static int		get_tens(intmax_t n)
{
	int tens;

	if (n < 0)
		n *= -1;
	tens = 1;
	while ((n /= 10) > 0)
		tens++;
	return (tens);
}

static char		get_negatvity_placeholder(t_printf *props, int is_negative)
{
	char	*tmp;

	tmp = props->flags;
	if (is_negative)
		return ('-');
	if (tmp[1] == '+')
		return ('+');
	if (tmp[2] == ' ')
		return (' ');
	return ('\0');
}

static t_printf	*do_d(t_printf *props, intmax_t n, int n_width, int align_left)
{
	int			not_blank;
	char		negatvity_placeholder;
	int			is_negative;

	is_negative = (n < 0) ? 1 : 0;
	n *= (is_negative && n != (-9223372036854775807 - 1)) ? -1 : 1;
	negatvity_placeholder = get_negatvity_placeholder(props, is_negative);
	not_blank = n_width;
	if (n_width <= props->precision && props->precision >= 0)
		not_blank = props->precision;
	if (negatvity_placeholder)
		not_blank++;
	props->ret += (not_blank <= props->width) ? props->width : not_blank;
	if (!align_left)
		put_filling(props, ' ', props->width - not_blank, 0);
	if (negatvity_placeholder)
		write(1, &negatvity_placeholder, 1);
	put_filling(props, '0', props->precision - n_width, 0);
	if (n != (-9223372036854775807 - 1))
		ft_putnbrmax(n);
	else if ((props->ret += 18) > 0)
		write(1, "9223372036854775808", 19);
	if (align_left)
		put_filling(props, ' ', props->width - not_blank, 0);
	return (props);
}

t_printf		*handle_d(t_printf *props)
{
	intmax_t	n;
	int			n_width;
	int			align_left;

	n = get_num(props);
	if (n == 0 && props->precision == 0)
	{
		if (props->flags[1] == '+')
			put_wchar_ret('+', props);
		if (props->flags[2] == ' ')
			put_wchar_ret(' ', props);
		put_filling(props, ' ', props->width, 1);
		return (props);
	}
	n_width = get_tens(n);
	align_left = (props->flags[0] == '-') ? 1 : 0;
	if (props->flags[3] == '0' && props->precision == -1 && !props->flags[0])
	{
		props->precision = props->width;
		if (n < 0 || props->flags[2] || props->flags[1] || props->flags[0])
			props->precision--;
	}
	do_d(props, n, n_width, align_left);
	return (props);
}
