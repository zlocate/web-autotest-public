/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:25:28 by rczarfun          #+#    #+#             */
/*   Updated: 2019/09/16 14:37:20 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char cut_haystack[len + 1];

	ft_memcpy(cut_haystack, haystack, len);
	cut_haystack[len] = 0;
	if (ft_strstr(cut_haystack, needle))
		return (ft_strstr(haystack, needle));
	return (0);
}
