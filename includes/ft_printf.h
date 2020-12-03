/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:52:26 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 20:26:23 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define SPECIFIERS "scSCdDiuUoOxXbp%"
# define CONVERTERS "-+ 0#"
# define ARGUMENTS "lhjz"

# include "../srcs/libft/libft.h"
# include <ctype.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

/*
** format: string (first ft_printf parameter).
** f_copy: copy of format.
** f_treat: copy of format.
** args: stores caradic arguments.
** len: ft_printf return value (number of printed characters).
** i: position of read in format string.
*/

typedef struct	s_printf
{
	const char	*format;
	char		*f_copy;
	char		*f_treat;
	va_list		args;
	int			len;
	size_t		i;
	long int	precision;
	long int	field_width;
	char		specifier_flag;
	char		convert[6];
	char		argument_flag[2];
}				t_printf;

int				ft_printf(const char *format, ...);
int				treatement(t_printf *tab);
int				parser(t_printf *tab);

t_printf		*init(t_printf *tab);
t_printf		*reinit(t_printf *tab);

t_printf		*parse_convert(t_printf *tab);
t_printf		*parse_field_width(t_printf *tab);
t_printf		*parse_precision(t_printf *tab);
t_printf		*parse_arguments(t_printf *tab);
t_printf		*parse_specifier(t_printf *tab);

t_printf		*handler(t_printf *tab);
t_printf		*handle_d(t_printf *tab);
t_printf		*handle_s(t_printf *tab);
t_printf		*handle_c(t_printf *tab);
t_printf		*handle_u(t_printf *tab);
t_printf		*handle_x(t_printf *tab);
t_printf		*handle_o(t_printf *tab);
t_printf		*handle_p(t_printf *tab);
t_printf		*handle_ws(t_printf *tab);
t_printf		*handle_other(t_printf *tab);
void			display_wchar(wint_t c, t_printf *tab);
void			display_gap(t_printf *tab, char c, int len, int update_len);

#endif
