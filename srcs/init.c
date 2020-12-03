/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:07:04 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:10:38 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*init(t_printf *props)
{
	props->ret = 0;
	props->i = 0;
	props->raw_string = (char *)props->raw_string;
	props->raw_string = (char *)props->raw_string;
	return (props);
}

t_printf	*reinit(t_printf *props)
{
	props->type = '\0';
	props->flags[0] = '\0';
	props->flags[1] = '\0';
	props->flags[2] = '\0';
	props->flags[3] = '\0';
	props->flags[4] = '\0';
	props->flags[5] = '\0';
	props->length[0] = '\0';
	props->length[1] = '\0';
	props->precision = -1;
	props->width = 0;
	return (props);
}
