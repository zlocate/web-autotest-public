/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:06:57 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:10:38 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handler(t_printf *props)
{
	props->i++;
	parse_flags(props);
	parse_width(props);
	parse_precision(props);
	parse_length(props);
	parse_type(props);
	handle_hub(props);
	return (props->ret);
}
