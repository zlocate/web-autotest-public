/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dissection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:04:53 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:04:55 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dissection(t_printf *tab)
{
	if (ft_strcmp(tab->raw_string, "%") == 0)
		return (0);
	while (tab->raw_string[tab->i] != '\0')
	{
		if (tab->raw_string[tab->i] == '%')
		{
			reinit(tab);
			handler(tab);
		}
		else
		{
			write(1, &tab->raw_string[tab->i], 1);
			tab->ret++;
		}
		tab->i++;
	}
	return (tab->ret);
}
