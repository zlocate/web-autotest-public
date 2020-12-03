/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:05:01 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:10:38 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *raw_string, ...)
{
	t_printf *props;

	if (!(props = (t_printf*)malloc(sizeof(t_printf))))
		return (-1);
	props->raw_string = raw_string;
	props = init(props);
	if (raw_string)
	{
		va_start(props->args, raw_string);
		props->ret = dissection(props);
		va_end(props->args);
	}
	free(props);
	return (props->ret);
}
