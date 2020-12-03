/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:52:37 by dhojt             #+#    #+#             */
/*   Updated: 2020/12/03 20:43:03 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *raw_string, ...)
{
	t_printf *tab;

	if (!(tab = (t_printf*)malloc(sizeof(t_printf))))
		return (-1);
	tab->raw_string = raw_string;
	tab = init(tab);
	if (raw_string)
	{
		va_start(tab->args, raw_string);
		tab->ret = parser(tab);
		va_end(tab->args);
	}
	free(tab);
	return (tab->ret);
}
