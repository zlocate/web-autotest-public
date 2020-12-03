/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:43:27 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/19 07:16:19 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr(int nb)
{
	if (nb < 0)
		ft_putchar('-');
	if ((nb >= 10) || (nb <= -10))
	{
		ft_putnbr(ft_abs(nb / 10));
		ft_putnbr(ft_abs(nb % 10));
	}
	else
		ft_putchar(ft_abs(nb) + '0');
}
