/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:12:33 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/12 17:51:36 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char tmp[len];

	if (!dst && !src)
		return (NULL);
	ft_memcpy(tmp, src, len);
	ft_memcpy(dst, tmp, len);
	return (dst);
}
