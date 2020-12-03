/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:06:43 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:26:26 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_leading_zero(uintmax_t n, char hash, char x)
{
	if (n)
	{
		if (hash == '#' && x == 'x')
			write(1, "0x", 2);
		if (hash == '#' && x == 'X')
			write(1, "0X", 2);
	}
}

static uintmax_t	get_num(t_printf *props)
{
	uintmax_t	n;

	if (ft_strcmp(props->length, "hh") == 0)
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

static t_printf		*do_x(t_printf *props, uintmax_t n, char *str, int align_l)
{
	int			n_b;
	int			n_w;

	if ((n_w = ft_strlen(str)) && props->flags[4] == '#' && n &&
			props->flags[3] == '0' && props->width)
		n_w += 2;
	else if ((n_w = ft_strlen(str)) && props->flags[4] == '#' && n)
	{
		props->width -= 2;
		props->ret += 2;
	}
	n_b = (n_w <= props->precision &&
	props->precision > 0) ? props->precision : n_w;
	props->ret += (n_b <= props->width) ? props->width : n_b;
	if (!align_l)
		put_filling(props, ' ', props->width - n_b, 0);
	print_leading_zero(n, props->flags[4], props->type);
	put_filling(props, '0', props->precision - n_w, 0);
	ft_putstr(str);
	if (align_l)
		put_filling(props, ' ', props->width - n_b, 0);
	return (props);
}

t_printf			*handle_x(t_printf *props)
{
	char		*str;
	char		c;
	uintmax_t	n;
	int			align_left;

	align_left = 0;
	n = get_num(props);
	if (n == 0 && props->precision == 0)
	{
		put_filling(props, ' ', props->width, 1);
		return (props);
	}
	c = 'a';
	if (props->type == 'X')
		c = 'A';
	if (!(str = ft_itoa_base(n, 16, c)))
		exit(-1);
	if (props->flags[0] == '-')
		align_left = 1;
	if (props->flags[3] == '0' && props->precision == -1 && !props->flags[0])
		props->precision = props->width;
	do_x(props, n, str, align_left);
	free(str);
	return (props);
}
