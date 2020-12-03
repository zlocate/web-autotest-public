/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:58:45 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/19 09:07:25 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t n;

	if (!*needle)
		return ((char *)haystack);
	n = ft_strlen(needle);
	while (*haystack)
	{
		if (!ft_memcmp(haystack, needle, n))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
