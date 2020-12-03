/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dissection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:04:53 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:10:38 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dissection(t_printf *props)
{
	if (ft_strcmp(props->raw_string, "%") == 0)
		return (0);
	while (props->raw_string[props->i] != '\0')
	{
		if (props->raw_string[props->i] == '%')
		{
			reinit(props);
			handler(props);
		}
		else
		{
			write(1, &props->raw_string[props->i], 1);
			props->ret++;
		}
		props->i++;
	}
	return (props->ret);
}
