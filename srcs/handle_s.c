/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:06:08 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:06:09 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf			*handle_s(t_printf *tab)
{
	char		*s;
	int			i;
	int			len;

	i = 0;
	s = va_arg(tab->args, char *);
	if (tab->precision > -1 && s)
		s = ft_strndup(s, tab->precision);
	else if (tab->precision == -1 && s)
		s = ft_strdup(s);
	else if (tab->precision > -1 && !s)
		s = ft_strndup("(null)", tab->precision);
	else if (tab->precision == -1 && !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	tab->ret += len;
	if (tab->flags[3] == '0' && tab->flags[0] != '-')
		put_filling(tab, '0', tab->width - len, 1);
	else if (tab->flags[0] != '-')
		put_filling(tab, ' ', tab->width - len, 1);
	ft_putstr(s);
	if (tab->flags[0] == '-')
		put_filling(tab, ' ', tab->width - len, 1);
	free(s);
	return (tab);
}
