/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:05:37 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:19:42 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_leading_zero(uintmax_t n, char hash)
{
	if (hash == '#' && n)
		write(1, "0", 1);
}

static uintmax_t	get_num(t_printf *props)
{
	uintmax_t	n;

	if (props->type == 'O')
		n = (unsigned long)(va_arg(props->args, unsigned long int));
	else if (ft_strcmp(props->length, "hh") == 0)
		n = (unsigned char)(va_arg(props->args, unsigned int));
	else if (ft_strcmp(props->length, "h") == 0)
		n = (unsigned short)(va_arg(props->args, unsigned int));
	else if (ft_strcmp(props->length, "ll") == 0)
		n = (unsigned long long)(va_arg(props->args, unsigned long long int));
	else if (ft_strcmp(props->length, "l") == 0)
		n = (unsigned long)(va_arg(props->args, unsigned long int));
	else if (ft_strcmp(props->length, "j") == 0)
		n = (uintmax_t)(va_arg(props->args, uintmax_t));
	else if (ft_strcmp(props->length, "z") == 0)
		n = (size_t)(va_arg(props->args, size_t));
	else
		n = (unsigned int)(va_arg(props->args, unsigned int));
	n = (uintmax_t)n;
	return (n);
}

static t_printf		*print_u(t_printf *props, uintmax_t n, char *str, int left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str);
	if (props->flags[4] == '#' && n)
		num_width++;
	not_blank = num_width;
	if (num_width <= props->precision && props->precision > 0)
		not_blank = props->precision;
	props->ret += (not_blank <= props->width) ? props->width : not_blank;
	if (!left)
		put_filling(props, ' ', props->width - not_blank, 0);
	print_leading_zero(n, props->flags[4]);
	put_filling(props, '0', props->precision - num_width, 0);
	ft_putstr(str);
	free(str);
	if (left)
		put_filling(props, ' ', props->width - not_blank, 0);
	return (props);
}

t_printf			*handle_o(t_printf *props)
{
	char		*str;
	uintmax_t	n;
	int			left;

	left = 0;
	n = get_num(props);
	if (n == 0 && props->precision == 0 && props->flags[4] != '#')
	{
		put_filling(props, ' ', props->width, 1);
		return (props);
	}
	if (!(str = ft_itoa_base(n, 8, 'a')))
		exit(-1);
	if (props->flags[0] == '-')
		left = 1;
	if (props->flags[3] == '0' && props->precision == -1 && !props->flags[0])
		props->precision = props->width;
	print_u(props, n, str, left);
	return (props);
}
