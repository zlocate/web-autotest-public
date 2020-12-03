/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wchar_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:07:37 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 22:10:38 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		oct_4(wint_t c)
{
	unsigned char put[4];

	put[0] = (c >> 18) + 240;
	put[1] = ((c >> 12) & 63) + 128;
	put[2] = ((c >> 6) & 63) + 128;
	put[3] = ((c & 63) + 128);
	write(1, put, 4);
}

static void		oct_3(wint_t c)
{
	unsigned char put[3];

	put[0] = (c >> 12) + 224;
	put[1] = ((c >> 6) & 63) + 128;
	put[2] = ((c & 63) + 128);
	write(1, put, 3);
}

static void		oct_2(wint_t c)
{
	unsigned char put[2];

	put[0] = (c >> 6) + 192;
	put[1] = ((c & 63) + 128);
	write(1, put, 2);
}

static void		oct_1(wint_t c)
{
	write(1, &c, 1);
}

void			put_wchar_ret(wint_t c, t_printf *props)
{
	if (c <= 127)
	{
		props->ret += 1;
		oct_1(c);
	}
	if (c >= 127 && c <= 2047)
	{
		props->ret += 2;
		oct_2(c);
	}
	if (c >= 2048 && c <= 65535)
	{
		props->ret += 3;
		oct_3(c);
	}
	if (c >= 65536 && c <= 2097151)
	{
		props->ret += 4;
		oct_4(c);
	}
}
