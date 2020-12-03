/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:52:37 by dhojt             #+#    #+#             */
/*   Updated: 2020/12/03 20:26:08 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf *tab;

	if (!(tab = (t_printf*)malloc(sizeof(t_printf))))
		return (-1);
	tab->format = format;
	tab = init(tab);
	if (format)
	{
		va_start(tab->args, format);
		tab->len = parser(tab);
		va_end(tab->args);
	}
	free(tab);
	return (tab->len);
}
