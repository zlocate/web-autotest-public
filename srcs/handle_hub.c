/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:05:27 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:05:28 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*handle_hub(t_printf *tab)
{
	char	*flag;

	flag = &tab->type;
	if (*flag == 'd' || *flag == 'i' || *flag == 'D')
		handle_d(tab);
	else if (*flag == 'c' || *flag == 'C')
		handle_c(tab);
	else if (*flag == 's' && ft_strcmp(tab->length, "l") == 0)
		handle_ws(tab);
	else if (*flag == 's')
		handle_s(tab);
	else if (*flag == 'S')
		handle_ws(tab);
	else if (*flag == 'u' || *flag == 'U')
		handle_u(tab);
	else if (*flag == 'x' || *flag == 'X')
		handle_x(tab);
	else if (*flag == 'o' || *flag == 'O')
		handle_o(tab);
	else if (*flag == 'p')
		handle_p(tab);
	else
		handle_other(tab);
	return (tab);
}
