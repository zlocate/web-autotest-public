/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:51:36 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/19 07:33:54 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
		ft_putchar_fd('-', fd);
	if ((nb >= 10) || (nb <= -10))
	{
		ft_putnbr_fd(ft_abs(nb / 10), fd);
		ft_putnbr_fd(ft_abs(nb % 10), fd);
	}
	else
		ft_putchar_fd(ft_abs(nb) + '0', fd);
}
