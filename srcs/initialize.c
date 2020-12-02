/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:43:08 by dhojt             #+#    #+#             */
/*   Updated: 2020/12/02 15:30:44 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*initialize(t_tab *tab)
{
	tab->len = 0;
	tab->i = 0;
	tab->f_treat = (char *)tab->format;
	tab->f_copy = (char *)tab->format;
	return (tab);
}
