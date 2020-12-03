/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:07:17 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:21:55 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*parse_flags(t_printf *props)
{
	size_t	i;

	i = 0;
	while (FLAGS[i] != '\0')
	{
		while (FLAGS[i] == props->raw_string[props->i])
		{
			while (props->raw_string[props->i] == '-' && props->i++)
				props->flags[0] = '-';
			while (props->raw_string[props->i] == '+' && props->i++)
				props->flags[1] = '+';
			while (props->raw_string[props->i] == ' ' && props->i++)
				props->flags[2] = ' ';
			while (props->raw_string[props->i] == '0' && props->i++)
				props->flags[3] = '0';
			while (props->raw_string[props->i] == '#' && props->i++)
				props->flags[4] = '#';
			i = 0;
		}
		i++;
	}
	return (props);
}

t_printf		*parse_width(t_printf *props)
{
	while (props->raw_string[props->i] >= '0' &&
	props->raw_string[props->i] <= '9')
	{
		props->width *= 10;
		props->width += (props->raw_string[props->i] - 48);
		props->i++;
	}
	return (props);
}

t_printf		*parse_precision(t_printf *props)
{
	while (props->raw_string[props->i] == '.')
	{
		props->i++;
		props->precision = 0;
	}
	while (props->raw_string[props->i] >= '0' &&
	props->raw_string[props->i] <= '9')
	{
		props->precision *= 10;
		props->precision += (props->raw_string[props->i] - 48);
		props->i++;
	}
	return (props);
}

t_printf		*parse_length(t_printf *props)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (LENGTHS[i] != '\0')
	{
		while (LENGTHS[i] == props->raw_string[props->i])
		{
			props->length[j] = props->raw_string[props->i];
			props->length[j + 1] = '\0';
			props->i++;
			j++;
		}
		i++;
	}
	return (props);
}

t_printf		*parse_type(t_printf *props)
{
	size_t	i;

	i = 0;
	while (SPECIFIERS[i] != '\0')
	{
		if (SPECIFIERS[i] == props->raw_string[props->i])
			props->type = SPECIFIERS[i];
		i++;
	}
	return (props);
}
