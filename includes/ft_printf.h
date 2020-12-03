/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:52:26 by rczarfun          #+#    #+#             */
/*   Updated: 2020/12/03 19:39:27 by rczarfun         ###   ########.fr       */
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

typedef struct	s_tab
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
}				t_tab;

int				ft_printf(const char *format, ...);
int				treatement(t_tab *tab);
int				parser(t_tab *tab);

t_tab			*initialize(t_tab *tab);
t_tab			*reinitialize(t_tab *tab);

t_tab			*parse_convert(t_tab *tab);
t_tab			*parse_field_width(t_tab *tab);
t_tab			*parse_precision(t_tab *tab);
t_tab			*parse_arguments(t_tab *tab);
t_tab			*parse_specifier(t_tab *tab);
t_tab			*switch_display(t_tab *tab);

t_tab			*display_d(t_tab *tab);
t_tab			*display_s(t_tab *tab);
t_tab			*display_c(t_tab *tab);
t_tab			*display_u(t_tab *tab);
t_tab			*display_x(t_tab *tab);
t_tab			*display_o(t_tab *tab);
t_tab			*display_p(t_tab *tab);
t_tab			*display_ws(t_tab *tab);
t_tab			*display_other(t_tab *tab);
void			display_wchar(wint_t c, t_tab *tab);
void			display_gap(t_tab *tab, char c, int len, int update_len);

#endif
