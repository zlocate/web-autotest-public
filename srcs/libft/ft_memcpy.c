/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:38:44 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/24 18:51:57 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dp;
	const unsigned char	*sp;

	if (!dst && !src)
		return (NULL);
	dp = (unsigned char*)dst;
	sp = (unsigned char*)src;
	while (n--)
		*dp++ = *sp++;
	return (dst);
}
