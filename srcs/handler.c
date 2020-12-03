/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:06:57 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:06:58 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handler(t_printf *tab)
{
	tab->i++;
	parse_flags(tab);
	parse_width(tab);
	parse_precision(tab);
	parse_length(tab);
	parse_type(tab);
	handle_hub(tab);
	return (tab->ret);
}
