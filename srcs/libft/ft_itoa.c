/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:50:13 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/25 16:39:37 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*ret;
	int		neg;

	neg = 1;
	if (n < 0)
	{
		if (!(ret = ft_strnew(ft_num_len(n) + 1)))
			return (NULL);
		ret[0] = '-';
		neg = 0;
	}
	else if (!(ret = ft_strnew(ft_num_len(n))))
		return (NULL);
	if (n == 0)
		*ret = '0';
	while (n)
	{
		ret[ft_num_len(n) - neg] = (ft_abs(n % 10) + '0');
		n /= 10;
	}
	return (ret);
}
