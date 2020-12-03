/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:06:57 by dhojt             #+#    #+#             */
/*   Updated: 2020/12/03 18:09:35 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab		*switch_display(t_tab *tab)
{
	char	*flag;

	flag = &tab->specifier_flag;
	if (*flag == 'd' || *flag == 'i' || *flag == 'D')
		display_d(tab);
	else if (*flag == 'c' || *flag == 'C')
		display_c(tab);
	else if (*flag == 's' && ft_strcmp(tab->argument_flag, "l") == 0)
		display_ws(tab);
	else if (*flag == 's')
		display_s(tab);
	else if (*flag == 'S')
		display_ws(tab);
	else if (*flag == 'u' || *flag == 'U')
		display_u(tab);
	else if (*flag == 'x' || *flag == 'X')
		display_x(tab);
	else if (*flag == 'o' || *flag == 'O')
		display_o(tab);
	else if (*flag == 'p')
		display_p(tab);
	else
		display_other(tab);
	return (tab);
}
