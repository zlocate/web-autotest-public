/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:06:30 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:17:59 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		char_len(wchar_t c)
{
	int len;

	if (c <= 127)
		len = 1;
	else if (c >= 127 && c <= 2047)
		len = 2;
	else if (c >= 2048 && c <= 65535)
		len = 3;
	else
		len = 4;
	return (len);
}

static wchar_t	*wstrndup(wchar_t *s1, size_t n)
{
	wchar_t	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = (wchar_t *)malloc(sizeof(wchar_t) * n + 1)))
		exit(-1);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static wchar_t	*wstrdup(wchar_t *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (wstrndup(str, len));
}

static t_printf	*do_null(t_printf *props)
{
	wchar_t		*s;
	int			i;

	i = 0;
	s = wstrdup(L"(null)");
	if (props->precision > -1)
	{
		while (s[i] && props->precision-- > 0)
			put_wchar_ret(s[i++], props);
	}
	else
	{
		while (s[i])
			put_wchar_ret(s[i++], props);
	}
	free(s);
	return (props);
}

t_printf		*handle_ws(t_printf *props)
{
	wchar_t		*s;
	int			i;
	int			j;
	int			len;

	i = 0;
	len = 0;
	if (!(s = (wchar_t *)va_arg(props->args, wchar_t *)))
		return (do_null(props));
	while (s[i] && !(j = 0))
	{
		if (props->precision > -1 && (len + char_len(s[i])) > props->precision)
			break ;
		len += char_len(s[i++]);
	}
	if (props->flags[3] == '0' && props->flags[0] != '-')
		put_filling(props, '0', props->width - len, 1);
	else if (props->flags[0] != '-')
		put_filling(props, ' ', props->width - len, 1);
	while (j < i)
		put_wchar_ret(s[j++], props);
	if (props->flags[0] == '-')
		put_filling(props, ' ', props->width - len, 1);
	return (props);
}
