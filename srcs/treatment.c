/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:55:14 by dhojt             #+#    #+#             */
/*   Updated: 2020/12/03 20:23:55 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		treatement(t_printf *tab)
{
	tab->i++;
	parse_convert(tab);
	parse_field_width(tab);
	parse_precision(tab);
	parse_arguments(tab);
	parse_specifier(tab);
	handler(tab);
	return (tab->len);
}
