/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:05:09 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:10:38 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf			*handle_c(t_printf *props)
{
	wint_t		c;

	if (ft_strcmp(props->length, "l") == 0)
		c = (unsigned long)va_arg(props->args, unsigned long);
	else if (props->type == 'C')
		c = (wchar_t)va_arg(props->args, wint_t);
	else
		c = (char)va_arg(props->args, int);
	c = (wint_t)c;
	if (props->flags[3] == '0' && props->flags[0] != '-')
		put_filling(props, '0', props->width - 1, 1);
	else if (props->flags[0] != '-')
		put_filling(props, ' ', props->width - 1, 1);
	put_wchar_ret(c, props);
	if (props->flags[0] == '-')
		put_filling(props, ' ', props->width - 1, 1);
	return (props);
}
