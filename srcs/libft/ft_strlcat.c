/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:26:00 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/13 19:29:57 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ret;
	size_t	j;

	i = ft_strlen(dst);
	ret = i + ft_strlen(src);
	j = 0;
	if (size < i)
		return (ft_strlen(src) + size);
	if (size > i + 1)
	{
		while (src[j] && j < (size - i - 1))
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = 0;
	}
	return (ret);
}
