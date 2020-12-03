/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:02:06 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/12 17:02:54 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned const char *)src)[i];
		if (((unsigned const char *)src)[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
