/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:05:49 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:15:31 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf		*display_percent(t_printf *props)
{
	if (props->flags[3] == '0' && props->precision <= 0 && !props->flags[0])
	{
		props->precision = props->width;
		props->width = 0;
	}
	if (props->flags[0] != '-')
		put_filling(props, ' ', props->width - 1, 1);
	if (props->flags[3] == '0')
		put_filling(props, '0', props->precision - 1, 1);
	write(1, "%", 1);
	if (props->flags[0] == '-')
		put_filling(props, ' ', props->width - 1, 1);
	props->ret++;
	return (props);
}

t_printf			*handle_other(t_printf *props)
{
	if (props->raw_string[props->i] == '%')
	{
		display_percent(props);
		return (props);
	}
	if (props->flags[3] == '0' && props->precision <= 0 && !props->flags[0])
	{
		props->precision = props->width;
		props->width = 0;
	}
	if (props->flags[0] != '-')
		put_filling(props, ' ', props->width - 1, 1);
	if (props->flags[3] == '0')
		put_filling(props, '0', props->precision - 1, 1);
	write(1, &props->raw_string[props->i], 1);
	if (props->flags[0] == '-')
		put_filling(props, ' ', props->width - 1, 1);
	props->ret++;
	return (props);
}
