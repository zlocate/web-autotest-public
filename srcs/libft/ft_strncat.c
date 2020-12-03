/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:39:07 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/16 13:16:36 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	while (src[j] && n--)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (dst);
}
