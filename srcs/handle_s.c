/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:06:08 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:10:38 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf			*handle_s(t_printf *props)
{
	char		*s;
	int			i;
	int			len;

	i = 0;
	s = va_arg(props->args, char *);
	if (props->precision > -1 && s)
		s = ft_strndup(s, props->precision);
	else if (props->precision == -1 && s)
		s = ft_strdup(s);
	else if (props->precision > -1 && !s)
		s = ft_strndup("(null)", props->precision);
	else if (props->precision == -1 && !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	props->ret += len;
	if (props->flags[3] == '0' && props->flags[0] != '-')
		put_filling(props, '0', props->width - len, 1);
	else if (props->flags[0] != '-')
		put_filling(props, ' ', props->width - len, 1);
	ft_putstr(s);
	if (props->flags[0] == '-')
		put_filling(props, ' ', props->width - len, 1);
	free(s);
	return (props);
}
