/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:07:17 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:07:18 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*parse_flags(t_printf *tab)
{
	size_t	i;

	i = 0;
	while (FLAGS[i] != '\0')
	{
		while (FLAGS[i] == tab->raw_string[tab->i])
		{
			while (tab->raw_string[tab->i] == '-' && tab->i++)
				tab->flags[0] = '-';
			while (tab->raw_string[tab->i] == '+' && tab->i++)
				tab->flags[1] = '+';
			while (tab->raw_string[tab->i] == ' ' && tab->i++)
				tab->flags[2] = ' ';
			while (tab->raw_string[tab->i] == '0' && tab->i++)
				tab->flags[3] = '0';
			while (tab->raw_string[tab->i] == '#' && tab->i++)
				tab->flags[4] = '#';
			i = 0;
		}
		i++;
	}
	return (tab);
}

t_printf	*parse_width(t_printf *tab)
{
	while (tab->raw_string[tab->i] >= '0' && tab->raw_string[tab->i] <= '9')
	{
		tab->width *= 10;
		tab->width += (tab->raw_string[tab->i] - 48);
		tab->i++;
	}
	return (tab);
}

t_printf	*parse_precision(t_printf *tab)
{
	while (tab->raw_string[tab->i] == '.')
	{
		tab->i++;
		tab->precision = 0;
	}
	while (tab->raw_string[tab->i] >= '0' && tab->raw_string[tab->i] <= '9')
	{
		tab->precision *= 10;
		tab->precision += (tab->raw_string[tab->i] - 48);
		tab->i++;
	}
	return (tab);
}

t_printf		*parse_length(t_printf *tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (LENGTHS[i] != '\0')
	{
		while (LENGTHS[i] == tab->raw_string[tab->i])
		{
			tab->length[j] = tab->raw_string[tab->i];
			tab->length[j + 1] = '\0';
			tab->i++;
			j++;
		}
		i++;
	}
	return (tab);
}

t_printf	*parse_type(t_printf *tab)
{
	size_t	i;

	i = 0;
	while (SPECIFIERS[i] != '\0')
	{
		if (SPECIFIERS[i] == tab->raw_string[tab->i])
			tab->type = SPECIFIERS[i];
		i++;
	}
	return (tab);
}
