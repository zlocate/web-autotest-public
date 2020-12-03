/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:05:27 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:10:38 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*handle_hub(t_printf *props)
{
	char	*flag;

	flag = &props->type;
	if (*flag == 'd' || *flag == 'i' || *flag == 'D')
		handle_d(props);
	else if (*flag == 'c' || *flag == 'C')
		handle_c(props);
	else if (*flag == 's' && ft_strcmp(props->length, "l") == 0)
		handle_ws(props);
	else if (*flag == 's')
		handle_s(props);
	else if (*flag == 'S')
		handle_ws(props);
	else if (*flag == 'u' || *flag == 'U')
		handle_u(props);
	else if (*flag == 'x' || *flag == 'X')
		handle_x(props);
	else if (*flag == 'o' || *flag == 'O')
		handle_o(props);
	else if (*flag == 'p')
		handle_p(props);
	else
		handle_other(props);
	return (props);
}
